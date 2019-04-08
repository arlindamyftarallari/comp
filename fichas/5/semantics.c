#include "structures.h"
#include "semantics.h"
#include "symbol_table.h"
#include <stdio.h>

int check_program(is_program* p) {
    int errorcount=0;

    errorcount=check_vardec_list(p->vlist, p->symtab);
    errorcount+=check_statement_list(p->slist, p->symtab);
    return errorcount;
}

int check_vardec_list(is_vardec_list* ivl, table_element * symtab) {
    int errorcount=0;
    is_vardec_list* tmp;
    
    for(tmp=ivl; tmp; tmp=tmp->next)
        errorcount+=check_vardec(tmp->val, symtab);
    return errorcount;
}

int check_vardec(is_vardec* iv, table_element * symtab) {
    switch(iv->disc_d) {
        case d_integer:
            return check_integer_dec(iv->data_vardec.u_integer_dec, symtab);
        case d_character:
            return check_character_dec(iv->data_vardec.u_character_dec, symtab);
        case d_double:
            return check_double_dec(iv->data_vardec.u_double_dec, symtab);    
    }
    return 0;
}

int check_integer_dec(is_integer_dec* iid, table_element * symtab) {
    table_element* newel=insert_el(iid->id, integer, symtab);

    if(newel==NULL) {
        printf("Line %d, column %d: Symbol %s already defined!\n", iid->line, iid->column, iid->id);
        return 1;
    }
    return 0;
}

int check_character_dec(is_character_dec* icd, table_element * symtab) {
        table_element* newel=insert_el(icd->id, character, symtab);

        if(newel==NULL) {
            printf("Line %d, column %d: Symbol %s already defined!\n", icd->line, icd->column, icd->id);
            return 1;
        }
        return 0;
}

int check_double_dec(is_double_dec* idd, table_element * symtab) {
    table_element* newel=insert_el(idd->id, doub, symtab);

    if(newel==NULL) {
        printf("Line %d, column %d: Symbol %s already defined!\n", idd->line, idd->column, idd->id);
        return 1;
    }
    return 0;
}

int check_statement_list(is_statement_list* isl, table_element * symtab) {
    int errorcount=0;
    is_statement_list* tmp;

    for(tmp=isl; tmp; tmp=tmp->next)
        errorcount+=check_statement(tmp->val, symtab);
    return errorcount;
}


int check_statement(is_statement* is, table_element * symtab) {
    switch(is->disc_d) {
        case d_write: return check_write_statement(is->data_statement.u_write_statement, symtab);    
    }
}

int check_write_statement(is_write_statement* iws, table_element * symtab) {
    table_element* aux=search_el(iws->id, symtab);

    if(aux==NULL) {
        printf("Line %d, column %d: Symbol %s not declared!\n", iws->line, iws->column, iws->id);
        return 1;
    }
    return 0;
}



