#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
int member;
struct nod * next;
}node;

void initializeList (node ** head, int data);
void addNode(node **list, int data);
void printList (node * head);
void deleteList (node * list);
int  countList (node * head);
void push(node **head, int n);
int pop(node ** head);
