#include "structures.h"
#include "symbol_table.h"

int check_program(is_program* p);
int check_vardec_list(is_vardec_list* ivl, table_element * symtab);
int check_vardec(is_vardec* iv, table_element * symtab);
int check_integer_dec(is_integer_dec* iid, table_element * symtab);
int check_character_dec(is_character_dec* icd, table_element * symtab);
int check_double_dec(is_double_dec* idd, table_element * symtab);
int check_statement_list(is_statement_list* isl, table_element * symtab);
int check_statement(is_statement* is, table_element * symtab);
int check_write_statement(is_write_statement* iws, table_element * symtab);