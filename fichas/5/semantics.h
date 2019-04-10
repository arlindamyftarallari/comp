#include "structures.h"
#include "symbol_table.h"

int check_program(is_program* p, int symtab_index);
int check_vardec_list(is_vardec_list* ivl, int symtab_index);
int check_vardec(is_vardec* iv, int symtab_index);
int check_integer_dec(is_integer_dec* iid, int symtab_index);
int check_character_dec(is_character_dec* icd, int symtab_index);
int check_double_dec(is_double_dec* idd, int symtab_index);
int check_statement_list(is_statement_list* isl, int symtab_index);
int check_statement(is_statement* is, int symtab_index);
int check_write_statement(is_write_statement* iws, int symtab_index);