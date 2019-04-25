#include "abstract_syntax_tree.h"
#include "symbol_table.h"
#include <unistd.h>
//function to create a new node of type "type" and value "value"
struct node * create_node (char* type, char* value, int line, int column) {
	
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->value = value;
	new->type = type;
	new->number_children = 0;
	new->parent = NULL;
	new->bro = NULL;
	new->line = line;
	new->column = column;

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

	if (strcmp(root->value, "") == 0) {
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

	if (strcmp(root->value, "") == 0) {
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

void annotate_tree(struct node * node) {

	if (strcmp(node->type, "Intlit") == 0) {
		annotate_node(node, "int");
	} 
	else if (strcmp(node->type, "Reallit") == 0) {
		annotate_node(node, "float32");
	}
	else if (strcmp(node->type, "Id") == 0) {
		//search for the symbol in the symbol table
		struct table_element * symbol = search_element(node->value, global_symtab);

		if (symbol == NULL) {
			printf("Line %d, column %d: Cannot find symbol %s\n", node->line, node->column, node->value);
			annotate_node(node, "undef");
		}
		else {
			//annotate the node with the type of the symbol in the symbol table
			if (symbol->decl_type == var) {
				annotate_node(node, symbol->decl.var.type);
			}
			else {
				annotate_node(node, symbol->decl.func.return_type);
			}
		}
	}
}

struct node *root = NULL;
