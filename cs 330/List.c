#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"
List newList(){
	List *L = malloc(sizeof(List));
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	return *L;
}
int size(const List *l){
	return l->size;
}
int empty(const List *l){
	return l->size == 0;
}
void add(List *l,void* item){
	struct node *n=newNode(item);
	if(l->size==0)
	l->head=l->tail=n;
	else{
		l->tail->next=n;
		l->tail=n;
	}
	l->size++;
}
void print(const List *l){
	struct node *n=l->head;
	printf("L(%d) = ",l->size);
	if(l->size==0){
		printf("Null\n");
	}else{
	while(n !=NULL){
		printf("%d ",n->data);
		n=n->next;
	}
	printf("\n");
}
}
void* get(const List *l,int index){
	if(index<0||index>=l->size){
		printf("Error: List index out of bounds %d. Exiting!\n",index);
		exit(EXIT_FAILURE);
	}
	struct node *n=l->head;
	for(int i=0;i<index;i++)
		n=n->next;
		return n->data;
}
void clear(List *l){
	struct node *n=l->head;
	struct node *nxt;
	while(n!=NULL){
		nxt=n->next;
		free(n);
		n=nxt;
	}
	l->head=l->tail=NULL;
	l->size=0;
}
void *contains(const List *l,void* item,int (*comp)(void *,void *)){
	struct node *n=l->head;
	int i=0;
	while(n !=NULL){
		if(comp(n->data,item)==0)
		return n->data;
		n=n->next;
	}
	return NULL;
}
