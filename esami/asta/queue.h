#define NULLQUEUE NULL
typedef struct c_queue *queue;

queue newQueue();
int emptyQueue(queue q);
int enqueue(queue q);
int dequeue(queue q);