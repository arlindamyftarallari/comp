#include "structures.h"
#include "semantics.h"
#include "symbol_table.h"
#include <stdio.h>

extern table_element * symtab_list[];

int check_program(is_program* p, int symtab_index) {
    int errorcount=0;

    errorcount = check_vardec_list(p->vlist, symtab_index);
    errorcount += check_statement_list(p->slist, symtab_index);
    return errorcount;
}

int check_vardec_list(is_vardec_list* ivl, int symtab_index) {
    int errorcount=0;
    is_vardec_list* tmp;
    
    for (tmp=ivl; tmp; tmp=tmp->next){ //iterates over vardec list and checks each vardec in it
        errorcount += check_vardec(tmp->val, symtab_index); 
	}
    
	return errorcount;
}

int check_vardec(is_vardec* iv, int symtab_index) {

    switch(iv->disc_d) { //disc_d can be either d_integer, d_character or d_double
	// iv->disc_d describes the type of the variable in iv->data_vardec 
        
		case d_integer: //INTEGER 
            return check_integer_dec(iv->data_vardec.u_integer_dec, symtab_index);
        case d_character: //CHARACTER
            return check_character_dec(iv->data_vardec.u_character_dec, symtab_index);
        case d_double: //DOUBLE
            return check_double_dec(iv->data_vardec.u_double_dec, symtab_index);
    }
    return 0;
}

int check_integer_dec(is_integer_dec* iid, int symtab_index) {

    table_element* newel=insert_el(iid->id, integer, symtab_index);

    if(newel==NULL) {
        printf("Line %d, column %d: Symbol %s already defined!\n", iid->line, iid->column, iid->id);
        return 1;
    }
    return 0;
}

int check_character_dec(is_character_dec* icd, int symtab_index) {

	table_element* newel=insert_el(icd->id, character, symtab_index);

	if(newel==NULL) {
		printf("Line %d, column %d: Symbol %s already defined!\n", icd->line, icd->column, icd->id);
		return 1;
	}
	return 0;
}

int check_double_dec(is_double_dec* idd, int symtab_index) {
    table_element* newel=insert_el(idd->id, doub, symtab_index);

    if(newel==NULL) {
        printf("Line %d, column %d: Symbol %s already defined!\n", idd->line, idd->column, idd->id);
        return 1;
    }
    return 0;
}

int check_statement_list(is_statement_list* isl, int symtab_index) {
    int errorcount=0;
    is_statement_list* tmp;

    for(tmp=isl; tmp; tmp=tmp->next)
        errorcount+=check_statement(tmp->val, symtab_index);
    return errorcount;
}


int check_statement(is_statement* is, int symtab_index) {
    switch(is->disc_d) {
        case d_write: return check_write_statement(is->data_statement.u_write_statement, symtab_index);    
    }
}

int check_write_statement(is_write_statement* iws, int symtab_index) {

    table_element* aux=search_el(iws->id, symtab_index);

    if(aux==NULL) {
        printf("Line %d, column %d: Symbol %s not declared!\n", iws->line, iws->column, iws->id);
        return 1;
    }
    return 0;
}



