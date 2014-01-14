#include<stdio.h>
#include<stdlib.h>

typedef struct edg {
char dst;
int weight;
struct edge * next;
}edge;

typedef struct nodeLst{
char name;
edge * nodeFirst;
}nodeList;

#define NUM 9
#define INF 1000
