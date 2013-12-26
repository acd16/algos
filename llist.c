#include "llist.h"

void initializeList (node **head, int data)
{
*head = malloc (sizeof (node));
(*head)-> member = data;
(*head)-> next = NULL;
}

void printList (node * head)
{
node *print = head;
printf("printing\n");
while (print != NULL)
    {
    printf ("%d %p \n", print->member, print);
    print = print -> next;
    }
}

int countList (node * head)
{
node *tab = head;
int count = 0;
while (tab != NULL)
    {
    count++;
    tab = tab -> next;
    }
return count;  
}

void addNode(node **list, int data)
{
node *newNode = NULL;
newNode = malloc (sizeof (node));
newNode -> member = data;
newNode -> next = NULL;
node **ins = NULL;
ins = list;
while (*ins != NULL)
    {
    ins = &((*ins) -> next);
    }
*ins = newNode;
}

void addNodeBeg(node **list, int data)
{
node *newNode = NULL;
newNode = malloc (sizeof (node));
newNode -> member = data;
newNode -> next = *list;
*list = newNode;
}

void deleteMatchNode(node **list, int match)
{
node **temp = list;
node **prev = NULL;
while (*temp != NULL)
    {
    if ((*temp)->member == match)
        break;
    prev = temp;
    temp = &(*temp)->next;
    }
node * save = *temp;
((*prev)->next) = ((*temp)->next);
printList(*list);
free(save);
}

int getNth(node * head, int n)
{
int i;
for (i=0;i<n-1;i++)
    head = head->next;
return head->member;
}

void pop()
{
}

void sort()
{
}

void join(node ** first, node ** second)
{
while (*first != NULL)
    { 
    first = &(*first)->next;
    }
*first = *second;
}

void deleteEnd(node **first)
{
node ** prev = NULL;
while (*first != NULL)
    {
    if ((*first)->next == NULL)
        {
        free(*first);
        (*prev)->next = NULL;
        break;
        }
    prev = first;
    first = &(*first)->next; 
    }
}

void sortList (node **list)
{
node ** temp = NULL;
temp = &(*list) -> next;
}

void deleteList (node *list)
{
node *temp=list;
while (list != NULL)
    {
    temp = list -> next;
    free (list);
    list = temp;
    }
}
