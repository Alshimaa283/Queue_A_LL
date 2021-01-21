#ifdef ARRAY_BASED_QUEUE

#include "../include/queue.h"

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
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void Append (QueueEntry e, Queue *pq)
{
    pq->rear =(pq->rear+1)%MAXQUEUE;
    pq->entry[pq->rear]=e;
    pq->size++;
}

void serve (QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front =(pq->front+1)%MAXQUEUE;
    pq->size--;
}
int QueueEmpty (Queue *pq)
{
    return !pq->size ;
}

int QueueFull (Queue *pq)
{
    return (pq->size==MAXQUEUE) ;
}

int QueueSize (Queue *pq)
{
    return pq->size ;
}
void  ClearQueue (Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
/*void TraverseQueue(Queue *pq , void (*pf)(QueueEntry))
{
    int pos , s;
    for (pos=pq->front; s=0 ; s<pq->size ; s++)
    {
        *(pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}*/
#else 


#include "../include/queue.h"
define QueueEntry int
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
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
void Append (QueueEntry e , Queue *pq)
{
     QueueNode *pn=(QueueNode *)malloc(sizeof (QueueNode));
    pn->next=NULL;
    pn->entry=e;
    if (!pq->rear)
        pq->front=pn ;
    else
        pq->rear->next=pn;
    pq->rear=pn;
    pq->size ++;
}

void serve (QueueEntry *pe, Queue *pq)
{
    QueueNode *pn = pq->front ;
    *pe=pn->entry ;
    pq->front =pn ->next ;
     free(pn);
     if (!pq->front)
        pq->rear=NULL;
     pq->size--;

}

int QueueEmpty (Queue *pq)
{
    return !pq->size ;
}

int QueueFull (Queue *pq)
{
    return 0;
}

int QueueSize (Queue *pq)
{
    return pq->size ;
}

void  ClearQueue (Queue *pq)
{

  while (pq->front)
  {
      pq->rear=pq->front->next;
      free(pq->front);
      pq->front = pq->rear;

  }
  pq->size=0;
}

#endif 
