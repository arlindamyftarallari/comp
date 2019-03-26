#include "structures.h"

//function to create a new node of type "type" and value "value"
struct node * create_node (char* type, char* name) {
	
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->name = name;
	new->type = type;
	new->children = NULL;

	return new;
}

//function to add a new child to the node parent, with type "type" and value "value"
struct node * create_child (char* type, char* name, struct node * parent) {

	struct node *new = create_node(type, name);

	parent->children[0] = (struct node *)malloc(sizeof(struct node));

	return new;
}