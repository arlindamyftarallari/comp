#include "abstract_syntax_tree.h"
#include "symbol_table.h"

//this function receives the root of the ast
void check_root(struct node * root);
void check_func_decl(struct node * node);
void check_var_decl(struct node * node, table_element * symtab);