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
while (*list != NULL)
    {
    list = &((*list) -> next);
    }
*list = newNode;
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
/*
node **temp = list;
    node **prev = NULL;
    while (*temp != NULL)
        {
            if ((*temp)->member == match)
                {
                    printf ("match found\n");
                    break;
                }
            prev = temp;
            temp = &(*temp) ->next;
        }
    printf("gg1 %p %p\n", *temp, *prev);
    (*prev)->next = (*temp)-> next;
    printf("gg %p %p\n", *temp, *prev);
    printList(*list);
    //free(*temp);
*/
node **temp = list;
node **prev = NULL;
while (*list != NULL)
    {
    if ((*list)->member == match)
        break;
    prev = list;
    list = &(*list)->next;
    }
((*prev)->next) = ((*list)->next);
free(*list);
}

int getNth(node * head, int n)
{
int i;
for (i=0;i<n-1;i++)
    head = head->next;
return head->member;
}

void push(node **head, int n)
{
node * newNode = NULL;
newNode = malloc (sizeof(node));
newNode -> member = n;
newNode -> next = *head;
*head = newNode;
}

void pop(node ** head)
{
node * temp = NULL;
if (*head == NULL)
    {
    printf("empty list \n");
    return;
    }
if ((*head)->next == NULL)
    {
    free(*head);
    *head = NULL;
    return;
    }
temp = *head;
*head = (*head)->next;
free(temp);
temp->next = NULL;
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

insertNth(node ** head, int pos, int val)
{
int i;
node ** prev;
for (i=0;i<pos-1 && (*head != NULL);i++)
    {
    prev = head;
    head = &(*head)->next;
    }
node * newNode = NULL;
newNode = malloc (sizeof (node));
newNode -> member = val;
newNode -> next = *head; 
(*prev)->next = newNode;
}

void split(node **head, node ** first, node ** second)
{
int size = 0, i, mid;
size = countList(*head);
printf ("size is %d\n", size); 
mid = size/2;
for (i=1;i<=mid;i++)
    {
    node * newNode = malloc(sizeof (node));
    newNode -> member = (*head)->member;
    if (i == mid)
        newNode -> next = NULL;
    else 
        newNode -> next = (*head)->next;
    *first = newNode;
    first = &(*first)->next;
    head = &(*head)->next;
    }
for (i=mid+1;i<=size; i++)
    {
    node * newNode = malloc(sizeof (node));
    newNode -> member = (*head)->member;
    if (i == size)
        newNode -> next = NULL;
    else 
        newNode -> next = (*head)->next;
    *second = newNode;
    second = &(*second)->next;
    head = &(*head)->next;
    }
}

void reverse(node ** head)
{
    node* prev   = NULL;
    node* current = *head;
    node* next;
    while (current != NULL)
    {
        printf ("bef %p %p %p %p\n", prev, current,current->next, next);
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
        printf ("af %p %p %p %p\n", prev, current, current->next, next);
    }
    *head = prev;
}

node ** findMatchNode (node ** head, int n)
{
while (*head != NULL)
    {
    if ((*head)->member == n)
        return head;
    head = &(*head)->next;
    }
}

void exchange (node ** head, int src, int dst)
{
node ** one = NULL;
node ** two = NULL;
one = findMatchNode (head, src);
two = findMatchNode (head, dst);
(*one)->member = dst;
(*two)->member = src;
}

void sortList (node **list)
{
node ** temp = NULL;
temp = &(*list) -> next;
}

void sortedInsert (node **list, int val)
{
int count = 0;
node *temp = *list;
while (*list != NULL)
    {
    count++;
    if (val <= (*list)->member)
        {
        insertNth(&temp, count, val);
        goto done;
        }
    list = &(*list)->next;
    }
if (*list == NULL){
initializeList(list, val);
    goto done;
}
addNode(list, val);
done: ;
}

node* insertSort (node **list)
{
node* new = NULL;
while (*list != NULL)
    {
    sortedInsert (&new, (*list)->member);
    list = &(*list)->next;
    }
deleteList(*list);
return new;
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
