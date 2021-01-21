#ifdef ARRAY_BASED_QUEUE

#define MAXQUEUE 100000
#define QueueEntry int
typedef struct queue
{
    int front ;
    int rear ;
    int size ;
     QueueEntry entry [MAXQUEUE];


} Queue ;
void  CreateQueue (Queue *pq)

void Append (QueueEntry e, Queue *pq)


void serve (QueueEntry *pe, Queue *pq)

int QueueEmpty (Queue *pq)


int QueueFull (Queue *pq)


int QueueSize (Queue *pq)

void  ClearQueue (Queue *pq)

/*void TraverseQueue(Queue *pq , void (*pf)(QueueEntry))
*/ 


#else

#define QueueEntry int
typedef struct queuenode
{
    QueueEntry entry ;
    struct queuenode *next ;

}QueueNode ;
typedef struct queue
{
    QueueNode *front ;
    QueueNode *rear;
    int size ;
}Queue ;


void  CreateQueue (Queue *pq)

void Append (QueueEntry e , Queue *pq)

void serve (QueueEntry *pe, Queue *pq)


int QueueEmpty (Queue *pq)


int QueueFull (Queue *pq)    

int QueueSize (Queue *pq)

void  ClearQueue (Queue *pq)


#endif 
