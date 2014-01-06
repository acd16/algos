#include "queue.h"

void enqueue(que ** q, int val)
{
node * newNode = malloc (sizeof (node));
newNode -> member = val;
newNode -> next = NULL;
if ((*q)->front == NULL)
    {
    (*q)->front = newNode;
    (*q)->rear = newNode;
    }
else
    {
    (*q)->rear->next = newNode;
    (*q)->rear = newNode;
    }
printf("enqueue %p %p %p \n", *q, (*q)->front, (*q)->rear);
}

void printQueue(que * q)
{
///////////////////////////////////////////
/*que * print = q;
while (print->front != NULL)
    {
    printf ("%d %p\n", print->front->member, print->front);
    print->front = print->front->next;
    }
printf("done %p %p\n", q, q->front);*/
///////////////////////////////////////////
node * print = q->front;
while (print != NULL)
    {
    printf ("%d %p\n", print->member, print->next);
    print = print -> next;
    }
}

void peek(que * q)
{
printf ("peek %d \n", q->front->member);
}

void deQueue(que ** q)
{
node * temp = (*q)->front->next;
printf ("Deq %d\n", (*q)->front->member);
free((*q)->front);
(*q)->front = temp;
}

void delQueue(que * q)
{
node * temp;
while (q->front != NULL)
    {
    temp = q->front->next;
    printf("node free %p\n", q->front);
    free(q->front);
    q->front = temp;
    }
printf("queue free %p\n", q);
free (q);
}
