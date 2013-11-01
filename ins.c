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
int visited[MAX] = {0};
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
        cur = cur->link;
        } 
    printf("\n");
    }
}

NODE insert (NODE *root, NODE temp){
NODE * mine;
mine = root;
    if (*mine == NULL)
        return temp;
    while(*mine != NULL){
    mine = &(*mine)->link;
    }
*mine = temp;
return *root;
}

int isAdjacent (NODE graph[], int src, int dst){
NODE cur = graph[src];
while (cur != NULL){
    if (cur->data == dst){
        return 1;
        }
    else
        cur = cur->link;
    }
return 0;
}

void dfs(int n, NODE graph[], int i)
{
int j;
visited[i]=1;
printf("%d ", i);
for (j=1;j<n;j++){
    if (!isAdjacent(graph, i, j) && !visited[j]){
        dfs(n, graph, j);
        }
    }
}

void callDfs(NODE graph[], int n)
{
int i;
for (i=0;i<n;i++){
    if(visited[i] == 0){
        dfs(n, graph, i);
        }
    }
}

main ()
{
int n=0;
int i, j;
int val;
char choice[2];
NODE temp, root;
printf("Enter the number of nodes\n");
scanf("%d", &n);
for (i=0;i<n;i++){
    root=NULL;
    while (1){
        printf("is there adjacent node for node %d:Y/N\n", i);
        scanf("%s", choice);
        if(!strcmp(choice,"N"))
            break;
        printf("enter the element \n");
        scanf("%d", &j);
	    temp = malloc(sizeof (struct node));
	    temp->data = j; 
	    temp->link = NULL;
	    root = insert(&root, temp);
    }
graph[i] = root; 
    }
for (j=0;j<n;j++)
    visited[j] = 0;
printf("The adjacency list is: \n");
displayGraph (graph, n);
printf("The dfs traversal is: \n");
callDfs(graph, n);
}
