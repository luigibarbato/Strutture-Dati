#include "item.h"
#define NULLQUEUE NULL
typedef struct c_queue *queue;

queue newQueue();
int emptyQueue(queue q);
int enqueue(queue q,item i);
item dequeue(queue q);
int sizeQueue(queue q);