#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
int mem;
struct Node * next;
}node;

node * addNode (node * head, int data)
{
node * temp = NULL;
if (head == NULL){
    temp = malloc (sizeof(node));
    temp->mem = data;
    temp->next = NULL;
    return temp;
    }
else {
    printf("first %p\n", head);
    temp = head;
    node * newNode = malloc (sizeof(node));
    newNode ->mem = data;
    newNode ->next = NULL;
    printf("sec %p\n", head);
    while(temp ->next != NULL){
        printf("im in");
        temp = temp ->next;
        }
    printf ("fin %p", head);
    temp -> next = newNode;
    return head;
    }
}

void printList(node * head)
{
while (head != NULL)
    {
    printf("%d \n", head->mem);
    head = head->next;
    }
}

void main ()
{
node * first;
first = addNode (first, 1);
first = addNode (first, 2);
printList (first);
}
