#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
int member;
struct nod * next;
}node;

void initializeList (node ** head, int data)
{
*head = malloc (sizeof (node));
(*head)-> member = data;
(*head)-> next = NULL;
}

void addNode(node **list, int data)
{
node *newNode = NULL;
newNode = malloc (sizeof (node));
newNode -> member = data;
newNode -> next = NULL;
node **ins = NULL;
ins = list;
printf ("%p\n", *ins);
while (*ins != NULL)
    {
    printf ("came in %p\n", *ins);
    ins = &(*ins) -> next;
    }
printf ("Done!!!\n");
*ins = newNode;
}

void printList (node * head)
{
node * print = head;
printf ("print start\n");
while (print != NULL)
    {
    printf ("%d ", print->member);
    print = print -> next;
    }
printf ("\nprint done\n");
}

void deleteList (node * list)
{
node * temp=list;
while (list != NULL)
    {
    temp = list -> next;
    free (list);
    list = temp;
    }
}

void main ()
{
node * head = NULL;
initializeList (&head, 5);
addNode(&head, 6);
addNode(&head, 7);
addNode(&head, 8);
addNode(&head, 9);
printList(head);
deleteList(head);
printList(head);
}
