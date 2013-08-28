#include<stdio.h>
void printi(int i[], int siz)
{
int j;
for (j=0;j<siz;j++)
    printf ("%d ", i[j]);
printf ("\n");
}
void main ()
{
int i[6] = {5,4,1,2,3,6};
int j, temp, k;
printi(i,6);
for (j=0;j<5;j++)
    {
    k=j+1;
    //printf ("\n before %d %d \n", i[k], i[k-1]);
    while (k>0)
        {
        if (i[k] < i[k-1])
            {
            temp=i[k];
            i[k]=i[k-1];
            i[k-1]=temp;
            }
        k--;
        }
    }
printi(i,6);
}
