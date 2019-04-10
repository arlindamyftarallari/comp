#include "symbol_table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern table_element * symtab_list[];


//Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element *insert_el(char *str, basic_type t, int symtab_index)
{
	table_element * newSymbol = (table_element*) malloc(sizeof(table_element));
	table_element * aux;
	table_element * previous;

	newSymbol->name = (char*)malloc(strlen(str)*sizeof(char));

	strcpy(newSymbol->name, str);
	newSymbol->type=t;
	newSymbol->next=NULL;	

	aux = symtab_list[symtab_index];

	if (aux != NULL) {

		do {
			if (strcmp(aux->name, str) == 0) return NULL; //cannot add new elem if if already exists
			previous = aux;
			aux = aux->next;

		} while (aux != NULL);

		//if while loop is over, then aux->next = NULL -> lets add new elem at the end of the list

		previous->next = newSymbol;
	}

	else {
		symtab_list[symtab_index] = newSymbol;
	}

	return newSymbol;
}

void show_table(int symtab_index)
{
	table_element *aux;
	printf("\n\tSHOW TABLE\n");
	for(aux=symtab_list[symtab_index]; aux; aux=aux->next)
		printf("symbol %s, type %d\n", aux->name, aux->type);
}

//Procura um identificador, devolve 0 caso nao exista
table_element *search_el(char *str, int symtab_index)
{
	table_element *aux;

	for(aux=symtab_list[symtab_index]; aux; aux=aux->next)
		if(strcmp(aux->name, str)==0)
			return aux;

	return NULL;
}





