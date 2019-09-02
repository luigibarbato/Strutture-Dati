struct nodo{
	item value;
	struct nodo *next;
};

typedef struct nodo *nodo;

struct c_queue queue{
	struct nodo *head,*tail;
	int size;
};

queue newQueue(){
	struct queue *q = malloc(sizeof(struct queue));
	q->head=NULL;
	q->tail=NULL;
	q->size=0;

	return q; 
}

int emptyQueue(queue q){
	if(q->head=NULL)
		return 0;
	else
		return -1;
}

int enqueue(queue q,item i){
	nodo n = malloc(sizeof(struct nodo));
	n->value=i;

	if(emptyQueue(q)){
		q->head=n;
	}
	else
	{
	 	q->tail->next=n;
	}

	q->tail=n;
	q->tail->size++:
	return 1;
}
item dequeue(queue q){

	if(emptyQueue(q))
		return NULLQUEUE
	 
		nodo n = malloc(sizeof(struct nodo));
		n=q->head;
		item i = q->head->value;
		q->head = q->head->next;
	
	if(q->head == NULL){
		q->tail=NULL;
	}
	
	q->tail->size--;
	
	return item;
}