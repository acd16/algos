#include <queue.h>

void main ()
{
node * head = NULL;
node * first = NULL;
node * second = NULL;
initializeList (&head, 5);
addNode(&head, 11);
insertNth(&head, 3, 7);
addNode(&head, 8);
addNode(&head, 10);
printList(head);
pairwiseSort(&head);
printList(head);
/*
head = insertSort (&head);
que * test = malloc (sizeof(que));
enqueue (&test, 5);
enqueue (&test,6);
enqueue (&test,7);
enqueue (&test,8);
peek(test);
printQueue(test);
deQueue (&test);
peek(test);
printQueue(test);
enqueue (&test,9);
peek(test);
printQueue(test);
delQueue(test);
sortedInsert(&head, 9);
printList(head);
addNode(&head, 10);
split (&head, &first, &second);
printList(head);
printList(first);
printList(second);
reverse(&head);
printList(head);*/
/*printList(head);
addNodeBeg(&head, 7);
deleteMatchNode (&head, 6);
insertNth(&head, 3, 11);
push (&head, 4);
exchange(&head, 8, 9);
printList(head);
pop(&head);
printf("after pop\n");
exit(1);
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
printf ("\n The count is %d\n", countList(head));*/
deleteList(head);
deleteList(first);
deleteList(second);
}
