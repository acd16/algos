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
int j, temp;
printi(i,6);
for (j=0;j<5;j++)
    {
    printf ("\n before %d %d \n", i[j], i[j+1]);
    if (i[j] > i[j+1])
        {
        temp=i[j];
        printf ("temp is %d", temp);
        i[j]=i[j+1];
        i[j+1]=temp;
        }
    printf ("\n after %d %d \n", i[j], i[j+1]);
    }
printi(i,6);
}
