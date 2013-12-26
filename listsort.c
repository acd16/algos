#include <llist.h>

void main ()
{
node * head = NULL;
node * second = NULL;
printf ("in main ");
initializeList (&head, 5);
addNode(&head, 6);
addNodeBeg(&head, 7);
addNode(&head, 8);
addNode(&head, 9);
printList(head);
deleteMatchNode(&head, 8);
printList(head);
initializeList (&second, 0);
addNode(&second, 1);
addNode(&second, 2);
addNode(&second, 3);
join(&head, &second);
printList(head);
deleteEnd(&head);
printList(head);
printf ("4th element is %d\n", getNth(head, 4));
printf ("\n The count is %d\n", countList(head));
deleteList(head);
}
