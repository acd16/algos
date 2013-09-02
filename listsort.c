#include <llist.h>

void main ()
{
node * head = NULL;
printf ("in main ");
initializeList (&head, 5);
addNode(&head, 6);
addNode(&head, 7);
addNode(&head, 8);
addNode(&head, 9);
printf("add %p  ", head);
printList(head);
printf("add %p  ", head);
printf ("\n The count is %d\n", countList(head));
//sortList(head);
deleteList(head);
}
