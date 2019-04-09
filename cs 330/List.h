#include "node.h"
typedef struct{
	int size;
	struct node *head;
	struct node *tail;
}List;
List newList();
int size(const List *l);
int empty(const List *l);
void clear(List *l);
void add(List *l,void* item);
void* get(const List *l,int index);
void* contains(const List *l,void* item,int (*comp)(void *,void *));
void print(const List *l);
void* *queryAirport(const List *l,char *code);
