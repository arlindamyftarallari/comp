#include "semantics.h"
#include <stdio.h>
#include <ctype.h>

//this function receives the root of the AST and checks the func and var declarations inside the tree
void check_root(struct node * root) {

	struct node * child;

	for (int i=0; i<root->number_children; i++) {
		child = root->children[i];

		if (strcmp(child->type, "FuncDecl") == 0) {
			check_func_decl(child);
		}

		else if (strcmp(child->type, "VarDecl") == 0) {
			check_var_decl(child, global_symtab);
		}
	}	
}

/* this function can be used either to add a new var declaration in the global symbol table
or inside a function. hence the need to specify the table */
void check_var_decl(struct node * node, table_element * symtab) {
	//this is a VarDecl, then we want to add the new var to the symbol table

	char * identifier = node->children[1]->value;
	char * type = node->children[0]->type;
	*type = tolower(*type);

	if (insert_vardecl(identifier, type, symtab) == NULL) printf("Troube inserting symbol\n");
}

void check_func_decl(struct node * node) {
	/* inserting the func declaration in the global symbol table, 
	but also inserting the parameters and local variable declarations inside it */

	char * return_type;
	struct node * funcparams;

	//children[0] is the FuncHeader
	if (node->children[0]->number_children == 2) { //this means that the function has no return type
		return_type = "none";
		funcparams = node->children[0]->children[1];
	}
	else { //there is a return type for this function
		
		return_type = (char*)malloc(strlen(node->children[0]->children[1]->type)*sizeof(char));

		//making return type lowercase
		//*return_type = tolower(*return_type);

		strcpy(return_type, node->children[0]->children[1]->type);
		*return_type = tolower(*return_type);
		funcparams = node->children[0]->children[2];
	}

	char * identifier = (char*)malloc(strlen(node->children[0]->children[0]->value)*sizeof(char));
	strcpy(identifier, node->children[0]->children[0]->value);

	//lets create the new symbol for this function

	table_element * function_symbol = insert_funcdecl(identifier, return_type);
	struct node * paramdecl;

	//--------------function parameters--------------------

	//for each param declaration inside the function parameters, we want to add a new symbol inside the function symbol (params)
	for (int i=0; i<funcparams->number_children; i++) {
		paramdecl = funcparams->children[i];
		if (insert_vardecl(paramdecl->children[1]->value, paramdecl->children[0]->type, function_symbol->decl.func.params) == NULL) {
			printf("Trouble inserting parameter declaration inside function\n");
		}
	}


	//------------function local variables-------------------

	//now we want to check the function body for any VarDecls

	struct node * funcbody = node->children[1];

	for (int i=0; i<funcbody->number_children; i++) {
		if (strcmp(funcbody->children[i]->type, "VarDecl") == 0) {
			if (insert_vardecl(funcbody->children[i]->children[1]->value, funcbody->children[i]->children[0]->type, function_symbol->decl.func.function_vars) == NULL) {
				printf("Troube inserting local variable declaration inside function\n");
			}
		}
	}

}