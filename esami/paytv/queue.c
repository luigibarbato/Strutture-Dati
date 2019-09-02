#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	item value;
	struct nodo *next;
};

struct c_queue{
	struct nodo *head,*tail;
	int size;
};

queue newQueue(){
	struct c_queue *q = malloc(sizeof(struct c_queue));
	q->head=NULL;
	q->tail=NULL;
	q->size=0;

	return q; 
}

int emptyQueue(queue q){
	if(q->head==NULL)
		return 0;
	else
		return -1;
}

int enqueue(queue q,item i){
	struct nodo *n = malloc(sizeof(struct nodo));
	n->value=i;

	if(q->head==NULL){
		q->head=n;
	}
	else{
		q->tail->next=n;
	}

	q->tail=n;
	q->size++;
	return 0;
}
item dequeue(queue q){

	if(q->head==NULL)
		return NULLQUEUE;

		struct nodo *n = q->head;
		item i = n->value;
		q->head = q->head->next;
		free(n);
		q->size--;
	if(q->head==NULL){
		q->tail=NULL;
	}
	return i;
}

int sizeQueue(queue q){

	return q->size;
}