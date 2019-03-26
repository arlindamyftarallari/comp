#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 15

typedef struct node {
	struct node * children[MAX_CHILDREN]; //list of children of this node
	char * type;
	char * name;
} node;


struct node *root = NULL;
 
struct node* create_node (char* type, char* name);
struct node* create_child(char* type, char* name, struct node * parent);