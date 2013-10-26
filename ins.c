#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct node{
    int data;
    struct node * link;
};
typedef struct node * NODE;
NODE graph[MAX];
void displayGraph (NODE graph[], int n)
{
int i;
NODE cur;
for (i=0;i<n;i++)
    {
    cur = graph[i];
    while(cur != NULL)
        {
        printf("%d ", cur->data);
        } 
    }
}

NODE insert (NODE root, NODE temp){
NODE mine;
mine = root;
    if (mine == NULL)
        return temp;
    while(mine != NULL){
    mine = mine->link;
    }
mine->link = temp;
return root;
}

main ()
{
int n=0;
int i, j;
int val;
char choice[2];
NODE temp, root;
printf("Enter the number of nodes\n");
for (i=0;i<3;i++){
    root=NULL;
    for (j=0;j<3;j++){
	    temp = malloc(sizeof (struct node));
	    temp->data = val; 
	    temp->link = NULL;
	    root = insert(root, temp);
    }
graph[i] = root; 
    }
displayGraph (graph, n);
}
