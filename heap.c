#include<stdio.h>
#include<stdlib.h>

int siz=0;

int * addElement(int *b, int data)
{
if (b==NULL)
    b = malloc (sizeof(int));
else 
    {
    b = realloc (b, ((siz+1) * sizeof(int)));
    }
b[siz] = data;
siz++;
printf("added %d and size %d\n", data, siz);
return b;
}

void printArray(int * a)
{
int i;
for (i=0;i<siz;i++)
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
int right = 2*l+2, left=2*l+1, lar;
//printf ("%d %d %d\n", b[l], b[left], b[right]);
if (left < (siz) && (b[left]>b[l]))
    lar = left;
else
    lar = l;
if (right< (siz) && (b[right]>b[lar]))
    lar = right;
if(lar != l)
    {
    printf("swapping %d %d\n", b[l], b[lar]);
    swap(&b[l], &b[lar]);
    maxHeapify(b, lar);
    }
//printf("gg %p\n", b);
return b;
}

buildMaxHeap(int * b)
{
int i;
for (i=siz/2;i>=0;i--)
    maxHeapify(b, i);
}

void heapSort(int * b)
{
int locSize = siz, i;
buildMaxHeap(b);
for (i=siz;i>0;i--)
    {
    swap(&b[0], &b[i]);
    siz--;
    maxHeapify(b,0);
    }
siz=locSize;
}

int getMaxPri(int * q)
{
    return q[0];
}

int getParent(int index)
{
if (index%2)
    return index/2;
else
    return (index/2)-1;
}

void incKey(int * q, int pos, int val)
{
int curPos = pos-1;
q[curPos] = val;
while((curPos>0) && (q[getParent(curPos)] < val))
    {
    swap(&q[getParent(curPos)], &q[curPos]);
    curPos = getParent(curPos);
    }
}

void decKey(int * q, int pos, int val)
{
int curPos = pos-1;
q[curPos] = val;
maxHeapify(q, curPos);
/*while((curPos>0) && (q[getParent(curPos)] < val))
    {
    swap(&q[getParent(curPos)], &q[curPos]);
    curPos = getParent(curPos);
    }*/
}

maxHeapAdd(int * q, int val)
{
q = addElement(q, val);
incKey(q, siz, val);
}

int main()
{
int *dyn=NULL;
/*dyn = addElement(dyn, 16);
dyn = addElement(dyn, 4);
dyn = addElement(dyn, 10);
dyn = addElement(dyn, 14);
dyn = addElement(dyn, 7);
dyn = addElement(dyn, 9);
dyn = addElement(dyn, 3);
dyn = addElement(dyn, 2);
dyn = addElement(dyn, 8);
dyn = addElement(dyn, 1);*/
dyn = addElement(dyn, 3);
dyn = addElement(dyn, 4);
dyn = addElement(dyn, 5);
dyn = addElement(dyn, 6);
dyn = addElement(dyn, 7);
dyn = addElement(dyn, 8);
dyn = addElement(dyn, 9);
dyn = addElement(dyn, 10);
dyn = addElement(dyn, 2);
dyn = addElement(dyn, 1);
printf("size %d\n", siz);
printArray(dyn);
buildMaxHeap(dyn);
//printf("the current max is %d\n", getMaxPri(dyn));
//heapSort(dyn);
printArray(dyn);
incKey(dyn, 10, 15);
printArray(dyn);
decKey(dyn, 1, 1);
printArray(dyn);
maxHeapAdd(dyn, 11);
printArray(dyn);
return 0;
}
