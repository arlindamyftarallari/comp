#include "structures.h"

//function to create a new node of type "type" and value "value"
struct node * create_node (char* type, char* value) {
	
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->value = value;
	new->type = type;
	new->number_children = 0;
	new->parent = NULL;

	printf("New node created with value=%s and type=%s\n", new->value, new->type);

	return new;
}

//function to add a new child to the node parent, with type "type" and value "value"
struct node * add_child (struct node *parent, struct node * child) {

	parent->children[parent->number_children] = child;
	parent->number_children++;
	child->parent = parent;

	printf("Added child of parent=%s created with value=%s and type=%s\n", parent->type,child->value, child->type);

	return parent;
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

