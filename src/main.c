
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_BASED_QUEUE
#include "queue.c"
int main()
{


Queue q;
    CreateQueue(&q);
    Append(6,&q);
    Append(8,&q);
    Append(10,&q);
    printf("the size is ");
    printf("%d\n",QueueSize(&q));



return 0;
}
