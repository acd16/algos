#include<stdio.h>
#include<stdlib.h>

int siz=0;

int * addElement(int *b, int data)
{
siz++;
if (b==NULL)
    b = malloc (sizeof(int));
else 
    {
    b = realloc (b, ((siz+1) * sizeof(int)));
    }
b[siz] = data;
return b;
}

void printArray(int * a)
{
int i;
for (i=1;i<=siz;i++)
    printf("%d ", a[i]);
printf("\n");
}

void swap(int *a, int *b)
{
int temp;
temp = *a;
*a=*b;
*b=temp;
}

int * maxHeapify(int * b, int l)
{
int right = 2*l+1, left=2*l, lar;
printf ("%d %d %d\n", b[l], b[left], b[right]);
if (left <= siz && b[left]>b[l])
    lar = left;
else
    lar = l;
if (right<= siz && b[right]>b[lar])
    lar = right;
if(lar != l)
    {
    printf("swapping %d %d\n", b[l], b[lar]);
    swap(&b[l], &b[lar]);
    maxHeapify(b, lar);
    }

printf("gg %p\n", b);
return b;
}

buildMaxHeap(int * b)
{
int i;
for (i=siz/2;i>0;i--)
    maxHeapify(b, i);
}

void heapSort(int * b)
{
int locSize = siz, i;
buildMaxHeap(b);
for (i=siz;i>=2;i--)
    {
    swap(&b[1], &b[i]);
    siz--;
    maxHeapify(b,1);
    }
siz=locSize;
}

int main()
{
int *dyn=NULL;
dyn = addElement(dyn, 16);
dyn = addElement(dyn, 4);
dyn = addElement(dyn, 10);
dyn = addElement(dyn, 14);
dyn = addElement(dyn, 7);
dyn = addElement(dyn, 9);
dyn = addElement(dyn, 3);
dyn = addElement(dyn, 2);
dyn = addElement(dyn, 8);
dyn = addElement(dyn, 1);
printArray(dyn);
heapSort(dyn);
printArray(dyn);
return 0;
}
