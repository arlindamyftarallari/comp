#include <stdio.h>
#include <string.h>

typedef enum {var, func} declaration_type;

typedef struct _t1 {
	char * type;
} vardecl;

typedef struct _t2 {
	char * return_type;
	struct table_element * params;
	struct table_element * function_vars;
} funcdecl;

//global symbol table elements can be either function or variable declarations
union declaration {
	vardecl var;
	funcdecl func;
} declaration;

typedef struct table_element {
	declaration_type decl_type; //is it a function or variable declaration?
	char * identifier;
	union declaration decl; //this has all the other fields
	struct table_element * next;
} table_element;

table_element * insert_vardecl(char * identifier, char * type, table_element ** symtab);
table_element * insert_funcdecl(char * identifier, char * return_type);
table_element * insert_element(table_element * new_symbol, table_element ** symtab);

table_element * search_element(char * identifier, table_element * symtab);

void print_table();
void free_table(table_element * symtab);

extern table_element * global_symtab;
extern table_element * to_print;
