#include "queue.h"

que * front = NULL;
que * rear = NULL;

void main ()
{
enqueue (5);
enqueue (6);
enqueue (7);
enqueue (8);
peek();
deQueue ();
printQueue();
peek();
printQueue();
enqueue (9);
peek();
printQueue();
}

void enqueue(int val)
{
que * newNode = malloc (sizeof (que));
newNode -> data = val;
newNode -> next = NULL;
if (front == NULL)
    {
    front = newNode;
    rear = newNode;
    }
else
    {
    rear -> next = newNode;
    rear = newNode;
    }
printf("enqueue %p %p\n", front, rear);
}

void deQueue()
{
que * temp = front->next;
printf ("Deq %d\n", front->data);
free(front);
front = temp;
}

void peek()
{
printf ("peek %d \n", front->data);
}

void delQueue()
{
que * temp;
while (front != NULL)
    {
    temp = front->next;
    free(front);
    front = temp;
    }
}

void printQueue()
{
que * temp;
temp = front;
while (temp != NULL)
    {
    printf ("%d %p\n", temp -> data, temp);
    temp = temp -> next;
    }
}
