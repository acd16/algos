//TODO : Add linked lists to get values from stdin
//       or file.

#include<stdio.h>
void printi(int i[], int siz)
{
int j;
for (j=0;j<siz;j++)
    printf ("%d ", i[j]);
printf ("\n");
}

void swap (int *i, int *j)
{
int temp;
temp = *i;
*i=*j;
*j=temp;
}

void main ()
{
int i[6] = {5,4,1,2,3,6};
int j, temp, k;
printi(i,6);
for (j=0;j<5;j++)
    {
    k=j+1;
    while (k>0)
        {
        if (i[k] < i[k-1])
            {
            swap(&i[k], &i[k-1]);
            }
        k--;
        }
    }
printi(i,6);
}
