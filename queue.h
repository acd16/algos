#include<stdio.h>
#include<stdlib.h>

#include "llist.h"

typedef struct queue{
node * front;
node * rear;
}que;


void enqueue(que **, int val);
void deQueue(que**);
void peek(que*);
void delQueue(que*);
void printQueue(que*);
