#include <llist.h>

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
