#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
int data;
struct queue * next;
}que;


void enqueue(int val);
void deQueue();
void peek();
void delQueue();
void printQueue();
