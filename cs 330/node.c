#include "node.h"
#include <stdlib.h>

struct node *newNode(void* item){
	struct node *n=malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
}
