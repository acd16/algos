#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
int member;
struct nod * next;
}node;
void addNode(node * first, node * second, int data)
{
head -> member = 5;
head -> next = sec;
}
void main ()
{
node *head = NULL, *sec = NULL, *third = NULL;
addNode (head, NULL, 5);
addNode (head, sec, 5);
addNode (head, third, 5);
head = malloc (sizeof (node));
sec = malloc (sizeof (node));
third = malloc (sizeof (node));
head -> member = 5;
head -> next = sec;
sec -> member = 6;
sec -> next = third;
third -> member = 7;
third -> next = NULL;
}
