#include "abstract_syntax_tree.h"
#include <unistd.h>

table_element * function_tracker;

//function to create a new node of type "type" and value "value"
struct node * create_node (char* type, char* value, int line, int column, int to_print) {
	
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->value = value;
	new->type = type;
	new->number_children = 0;
	new->parent = NULL;
	new->bro = NULL;
	new->line = line;
	new->column = column;
	new->to_print = to_print;

	//printf("created new node %s(%s)\n\n", type, value);
	return new;
}

//function to add a new child to the node parent, with type "type" and value "value"
struct node * add_child (struct node *parent, struct node * child) {
	struct node * aux;

	if (child == NULL || parent == NULL) return NULL;

	parent->children[parent->number_children] = child;
	parent->number_children++;
	child->parent = parent;

	aux = child->bro;

	while (aux != NULL) { //iterates over child's siblings to add parent as a parent to them too
		aux->parent = parent;
		parent->children[parent->number_children] = aux;
		parent->number_children++;
		//printf("added child %s(%s) to parent %s(%s)\n\n", aux->type, aux->value, parent->type, parent->value);
		aux = aux->bro;
	}

	//printf("added child %s(%s) of parent %s(%s)\n\n", child->type, child->value, parent->type, parent->value);


	return parent;
}

struct node * add_sibling(struct node * s1, struct node * s2) {
	struct node * aux = s1;

	if (aux != NULL) {
		while (aux->bro != NULL) {
			aux = aux->bro;
		}
		aux->bro = s2;
	}
	//if(s1!=NULL && s2!=NULL) printf("added %s(%s) and %s(%s) as siblings\n", s1->type, s1->value,s2->type, s2->value);
	return s1;
}

//function to get the number of siblings of a given node
int get_number_siblings(struct node* node) {
	if (node->parent != NULL) {
		return node->parent->number_children;
	}
	return 0;
	
}

//function to print the tree in order
void print_node(struct node * root, int depth) {
	char * points = "";
	int i;

	if (root == NULL) return;

	//printf("node=%s children=%d\n", root->type, root->number_children);

	//puts the appropriate number of points

	for (i=0; i<depth; i++) {
		printf("..");
	}

	if (!root->to_print) {
		printf("%s%s\n", points, root->type);
	}
	else {
		printf("%s%s(%s)\n", points, root->type, root->value);
	}

	for (int j=0; j<root->number_children; j++) {
		print_node(root->children[j], depth+1);
	}

	free(root);

}

void print_annotated_node(struct node * root, int depth) {
	char * points = "";
	int i;

	if (root == NULL) return;

	for (i=0; i<depth; i++) {
		printf("..");
	}

	if (!root->to_print) {
		printf("%s%s", points, root->type);
	}
	else {
		printf("%s%s(%s)", points, root->type, root->value);
	}

	if (strcmp(root->annotation, "") != 0) {
		printf(" - %s\n", root->annotation);
	}
	else printf("\n");
}

void annotate_node(struct node * node, char * annotation) {
	node->annotation = (char*)malloc(strlen(annotation)*sizeof(char));
	strcpy(node->annotation, annotation);
}

void annotate_tree(struct node * node, struct table_element * symtab) {

	printf("Annotating node %s\n", node->type);

	if (strcmp(node->type, "IntLit") == 0) {
		annotate_node(node, "int");
	} 
	else if (strcmp(node->type, "RealLit") == 0) {
		annotate_node(node, "float32");
	}
	else if (strcmp(node->type, "Id") == 0) {
		//search for the symbol in the symbol table
		struct table_element * symbol = search_element(node->value, symtab);

		if (symbol == NULL && symtab != global_symtab) {
			printf("OI\n");
			symbol = search_element(node->value, global_symtab);
		}

		if (symbol == NULL) {
			printf("Line %d, column %d: Cannot find symbol %s\n", node->line, node->column, node->value);
			annotate_node(node, "undef");
		}

		else {
			//annotate the node with the type of the symbol in the symbol table
			if (symbol->decl_type == var) {
				annotate_node(node, symbol->decl.var.type);
			}
			else { //the ID matches to a function
				
				/* if this ID matches a function, we want to start looking up things in 
				the symbol table of that function, unless we're dealing with a funcinvocation */
				if (node->parent != NULL && strcmp(node->parent->type, "Call") != 0) function_tracker = symbol; 
				printf("Now tracking function: %s\n", function_tracker->identifier);
				annotate_node(node, symbol->decl.func.return_type);
			}
		}
	}
	else if (strcmp(node->type, "Call") == 0) {

		/* first, we have to annotate the nodes of the vars given as arguments,
		so that later on we can check if they match with the expected types */

		for (int i=1; i<node->number_children; i++) {
			annotate_tree(node->children[i], symtab);
		}

		// node = Call
		
		// annotating the ID of the function Call with the types of the parameters 

		struct node * functionID = node->children[0];

		table_element * functionID_symbol = search_element(functionID->value, symtab);

		if (functionID_symbol == NULL) {
			printf("Line %d, column %d: Cannot find symbol %s\n", functionID->line, functionID->column, functionID->value);
			annotate_node(node, "undef");
			annotate_node(functionID, "undef");
		}

		else {

			char * arguments = (char*)malloc(500*sizeof(char));
			strcat(arguments, "(");

			char * expected = (char*)malloc(500*sizeof(char));
			strcat(expected, "(");

			char * type;
			table_element * aux = functionID_symbol->decl.func.function_vars;

			// what argument types are really used?
			for (int i=1; i<node->number_children-1; i++) { //the first child is the function ID
				type = node->children[i]->annotation;
				strcat(arguments, type);
				strcat(arguments, ",");
			}
			arguments[strlen(arguments)-1] = '\0';
			strcat(arguments, ")");

			// what parameter types were expected?
			for (int i=0; i<functionID_symbol->decl.func.number_params; i++) {
				type = aux->decl.func.function_vars->decl.var.type;
				strcat(expected, type);
				strcat(expected, ",");
			}

			expected[strlen(expected)-1] = '\0';
			strcat(expected, ")");

			if (strcmp(expected, arguments) != 0) { // this means that the types used don't match to the ones expected, or the number of arguments is not correct
				printf("Line %d, column %d: Cannot find symbol %s%s\n", node->line, node->column, node->type, arguments);
				annotate_node(node, "undef");
			}
			else {
				annotate_node(node, functionID_symbol->decl.func.return_type);
			}

			annotate_node(functionID, expected);
		}

	}
	else if (strcmp(node->type, "Not") == 0) {
		annotate_tree(node->children[0], symtab);

	}
	else if (strcmp(node->type, "Minus") == 0) {
		annotate_tree(node->children[0], symtab);
	}
	else if (strcmp(node->type, "Plus") == 0) {
		annotate_tree(node->children[0], symtab);
	}
	else if(strcmp(node->type, "Or") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "And") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Lt") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Gt") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Eq") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);

	}
	else if(strcmp(node->type, "Ne") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Le") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Ge") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}
	else if(strcmp(node->type, "Add") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);

		if (strcmp(node->children[0]->annotation, node->children[1]->annotation) != 0) {
			/* ERROR */

			printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",
													node->line,
													node->column,
													node->value,
													node->children[0]->annotation,
													node->children[1]->annotation);
			annotate_node(node, "undef");
		}
		else { //same type
			annotate_node(node, node->children[0]->annotation);
		}
	}
	else if(strcmp(node->type, "Sub") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);

		if (strcmp(node->children[0]->annotation, node->children[1]->annotation) != 0) {
			/* ERROR */
			printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",
													node->line,
													node->column,
													node->type,
													node->children[0]->annotation,
													node->children[1]->annotation);
			annotate_node(node, "undef");
		}
		else { //same type
			annotate_node(node, node->children[0]->annotation);
		}
	}
	else if(strcmp(node->type, "Mul") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);

		if (strcmp(node->children[0]->annotation, node->children[1]->annotation) != 0) {
			/* ERROR */
			printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",
													node->line,
													node->column,
													node->type,
													node->children[0]->annotation,
													node->children[1]->annotation);
			annotate_node(node, "undef");
		}
		else { //same type
			annotate_node(node, node->children[0]->annotation);
		}
	}
	else if(strcmp(node->type, "Div") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);

		if (strcmp(node->children[0]->annotation, node->children[1]->annotation) != 0) {
			/* ERROR */
			printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",
													node->line,
													node->column,
													node->type,
													node->children[0]->annotation,
													node->children[1]->annotation);
			annotate_node(node, "undef");
		}
		else { //same type
			annotate_node(node, node->children[0]->annotation);
		}
	}
	else if(strcmp(node->type, "Mod") == 0) {
		annotate_tree(node->children[0], symtab);
		annotate_tree(node->children[1], symtab);
	}

	/* FuncDecls need to be treated specially */
	else if (strcmp(node->type, "FuncDecl") == 0) {
		function_tracker = global_symtab;

		annotate_tree(node->children[0], function_tracker);

		//at this point, function_tracker has the symbol of the function
		printf("About to enter FuncBody, tracking %s\n", function_tracker->identifier);
		annotate_tree(node->children[1], function_tracker->decl.func.function_vars);
	}

	else if (strcmp(node->type, "FuncHeader") == 0) {
		annotate_tree(node->children[0], function_tracker); /* after executing this, function_tracker will change
		to be the symbol of the function in the table */

		for (int i=1; i<node->number_children; i++) {
			annotate_tree(node->children[i], function_tracker->decl.func.function_vars);
		}
	}

	else if (strcmp(node->type, "Program") == 0) {
		function_tracker = global_symtab;
		for (int i=0; i<node->number_children; i++) {
			annotate_tree(node->children[i], function_tracker);
		}
	}

	else {
		for (int i=0; i<node->number_children; i++) {
			annotate_tree(node->children[i], symtab);
		}
	}
}

struct node *root = NULL;
