#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//inserts new variable declaration in the given table
//variable declarations are part of function declarations too
table_element * insert_vardecl(char * identifier, char * type, table_element * symtab) {
	
	table_element * new_symbol = (table_element*)malloc(sizeof(table_element));

	new_symbol->decl_type = var;

	new_symbol->identifier = (char*)malloc(strlen(identifier)*sizeof(char));
	strcpy(new_symbol->identifier, identifier);

	new_symbol->next = NULL;

	new_symbol->decl.var.type = (char*)malloc(strlen(type)*sizeof(char));
	strcpy(new_symbol->decl.var.type, type);

	return insert_element(new_symbol, symtab);
}

table_element * insert_funcdecl(char * identifier, char * return_type, table_element * params, table_element * functionvars) {

	table_element * new_symbol = (table_element*)malloc(sizeof(table_element));

	new_symbol->decl_type = func;

	new_symbol->identifier = (char*)malloc(strlen(identifier)*sizeof(char));
	strcpy(new_symbol->identifier, identifier);

	new_symbol->next = NULL;

	new_symbol->decl.func.return_type = (char*)malloc(strlen(return_type)*sizeof(char));
	strcpy(new_symbol->decl.func.return_type, return_type);
	new_symbol->decl.func.params = params;
	new_symbol->decl.func.function_vars = functionvars;

	return insert_element(new_symbol, global_symtab);
}

table_element * insert_element(table_element * new_symbol, table_element * symtab) {

	table_element * aux = symtab;
	table_element * previous;

	if (aux != NULL) {

		do {
			//not possible to add another symbol with the same identifier
			if (strcmp(aux->identifier, new_symbol->identifier) == 0) return NULL;

			previous = aux;
			aux = aux->next;

		} while (aux != NULL);

		//at this point, aux = NULL
		//add new_symbol after previous

		previous->next = new_symbol;
	}

	else {
		symtab = new_symbol;
	}
	return new_symbol;
}

table_element * search_element(char * identifier, table_element * symtab) {

	table_element * aux = symtab;

	while (aux != NULL) {
		
		if (strcmp(aux->identifier, identifier) == 0) return aux; //this is the one we're searching for!
		aux = aux->next;
	}

	return NULL; //element not found
}

void print_table() {

	table_element * aux = global_symtab;
	table_element * params;

	printf("===== Global Symbol Table =====\n");

	while (aux != NULL) { //iterates over the global symbol table

		//variable declarations
		if (aux->decl_type == var) {
			printf("%s\t%s\n", aux->identifier, aux->decl.var.type);
		}

		//function declarations
		else {
			printf("%s\t(", aux->identifier);

			if (aux->decl.func.params != NULL) { //iterates over parameters and prints their type

				params = aux->decl.func.params;

				printf("%s", params->decl.var.type);

				while (params->next != NULL) {
					params = params->next;
					printf(", %s", params->decl.var.type);
				}
			}

			printf(")\t");

			//function return type

			printf("%s", aux->decl.func.return_type);

			//adds this node to be printed after the global symbol table
			insert_element(aux, to_print);
		}

	}

	//printing functions symbol tables

	aux = to_print;

	while (aux != NULL) {

		printf("\n===== Function %s(", aux->identifier);

		if (aux->decl.func.params != NULL) {
			params = aux->decl.func.params;

			printf("%s", params->decl.var.type);

			while (params->next != NULL) {
					params = params->next;
					printf(", %s", params->decl.var.type);
				}
		}

		printf(") Symbol Table =====\n");

		printf("return\t%s", aux->decl.func.return_type);

		//prints the parameters

		params = aux->decl.func.params;

		while (params != NULL) {
			printf("\n%s\t%s\tparam", params->identifier, params->decl.var.type);
			params = params->next;
		}

		//prints the local variables

		params = aux->decl.func.function_vars;

		while (params != NULL) {
			printf("\n%s\t%s", params->identifier, params->decl.var.type);
			params = params->next;
		}

		printf("\n");

		aux = aux->next;
	}


}