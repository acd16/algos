#include<llist.h>

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
    printf ("%d ", print->member);
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
    ins = &(*ins) -> next;
    }
*ins = newNode;
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
