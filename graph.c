#include "graph.h"
#include "llist.h"

void printAdj (edge * edj)
{
edge * temp = edj;
while (temp != NULL)
    {
    printf ("%c %d ", temp-> dst, temp->weight);
    temp = temp -> next;
    }
printf ("\n");
}

void printAdjList(nodeList ** graph, int nodes)
{
int i;
for (i=0;i<nodes;i++)
    {
    printAdj(graph[i]->nodeFirst);
    }
}

void addEdge (nodeList ** headEdge, char d, int w)
{

if (d<97)
   d += 97; 

edge * newEdge = malloc (sizeof(edge));
newEdge->dst = d;
newEdge->weight= w;
newEdge->next = NULL;
if (*headEdge == NULL)
    {
    *headEdge = malloc(sizeof (nodeList));
    (*headEdge)->name = 'a';
    (*headEdge)->nodeFirst = newEdge;
    }
else 
    {
    edge ** mine = &(*headEdge)->nodeFirst;
    while ((*mine) != NULL)
        {
        mine = &(*mine)->next;
        }
    *mine = newEdge;
    }
}

int findMin(int * dst, int num, int * visited)
{
int i, min=INF, next;
for (i=0;i<num;i++)
    {
    if((min >= dst[i]) && !visited[i])
        {
        min = dst[i];
        next = i;
        }
    }
return next;
}

void dij(nodeList ** graph, int num, int src)
{
int *dst, *visited, *pre, i,j, min, tmpNum;
edge * dijEdge;
dst = malloc (num * sizeof(int));
for (i=0;i<num;i++)
    dst[i] = INF;

dst[src] = 0;

visited = malloc (num * sizeof(int));
for (i=0;i<num;i++)
    visited[i] = 0;

pre = malloc (num * sizeof(int));
for (i=0;i<num;i++)
    pre[i] = -1;

for (i=0;i<num;i++)
    {
    min = findMin(dst, num, visited);
    dijEdge = graph[min]->nodeFirst;
    while (dijEdge != NULL)
        { 
        tmpNum = dijEdge->dst - 97;  
        if (dst[tmpNum]>dst[min] + dijEdge->weight)
            {
            dst[tmpNum] = dst[min] + dijEdge->weight;
            pre[tmpNum] = min;
            }
        dijEdge = dijEdge->next;
        }
    visited[min] = 1;
    }
for (j=0;j<num;j++)
    printf("%d ", dst[j]);
printf("\n");
}

void doDfs(nodeList ** graph)
{
int * visited = malloc (NUM * sizeof (int)), v;
node * head = NULL;
edge * temp = NULL;
push(&head, 0);
while(head != NULL)
    {
    v = pop(&head);
    if(visited[v] != 1)
        {
        printf ("%d visited \n", v);
        visited[v] = 1;
        temp = graph[v]->nodeFirst;
        while(temp != NULL)
            {
            if (temp->dst >= 97)
                temp->dst -= 97;
            push(&head, temp->dst);
            temp = temp->next;
            }
        }
    }
}

void main ()
{
int i = sizeof (nodeList);
edge * graphEdge;
nodeList ** graph1 = malloc (NUM * sizeof (nodeList *));
/*addEdge(&graph1[0], 'b', 3);
addEdge(&graph1[0], 'c', 5);
addEdge(&graph1[0], 'd', 1);
addEdge(&graph1[1], 'a', 3);
addEdge(&graph1[1], 'c', 1);
addEdge(&graph1[1], 'd', 2);
addEdge(&graph1[2], 'a', 5);
addEdge(&graph1[2], 'b', 1);
addEdge(&graph1[2], 'd', 2);
addEdge(&graph1[3], 'a', 1);
addEdge(&graph1[3], 'b', 2);
addEdge(&graph1[3], 'c', 2);*/
addEdge(&graph1[0], 1, 4);
addEdge(&graph1[1], 0, 4);
addEdge(&graph1[0], 7, 8);
addEdge(&graph1[7], 0, 8);
addEdge(&graph1[1], 2, 8);
addEdge(&graph1[2], 1, 8);
addEdge(&graph1[1], 7, 11);
addEdge(&graph1[7], 1, 11);
addEdge(&graph1[2], 8, 2);
addEdge(&graph1[8], 2, 2);
addEdge(&graph1[7], 8, 7);
addEdge(&graph1[8], 7, 7);
addEdge(&graph1[8], 6, 6);
addEdge(&graph1[6], 8, 6);
addEdge(&graph1[7], 6, 1);
addEdge(&graph1[6], 7, 1);
addEdge(&graph1[2], 3, 7);
addEdge(&graph1[3], 2, 7);
addEdge(&graph1[2], 5, 4);
addEdge(&graph1[5], 2, 4);
addEdge(&graph1[6], 5, 2);
addEdge(&graph1[5], 6, 2);
addEdge(&graph1[3], 5, 14);
addEdge(&graph1[5], 3, 14);
addEdge(&graph1[3], 4, 9);
addEdge(&graph1[4], 3, 9);
addEdge(&graph1[4], 5, 10);
addEdge(&graph1[5], 4, 10);
//dij(graph1, NUM, 0);
doDfs(graph1);
}
