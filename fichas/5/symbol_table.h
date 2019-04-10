#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {integer, character, doub} basic_type;

typedef struct _t1{
	char *name;
	basic_type type;
	struct _t1 *next;
} table_element;

table_element *insert_el(char *str, basic_type t, int symtab_index);
void show_table(int symtab_index);
table_element *search_el(char *str, int symtab_index);

#endif
