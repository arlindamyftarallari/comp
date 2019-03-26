#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	node * * child; //list of children of this node
	char * type;
	char * name;
} node;

