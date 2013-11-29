#include<stdio.h>
int matrix[10][10] =  {0};
void marshal(int mine[][], int v){
int k, j, i;
for (k=1;k<=v;k++)
    for (i=1;i<=v;i++)
        for (j=1;j<=v;j++)
 	    if(((mine[i][k])+mine[k][j]) < mine[i][j]) mine[i][j]=((mine[i][k])+mine[k][j]);
}
int main ()
{
int n, i, j;
printf ("enter the number of vertices\n");
scanf("%d", &n);
for (i=0;i<n;i++){
    for (j=0;j<n;j++){
        printf("Enter the distance between %d and %d vertices\n", i, j);
        scanf("%d", &matrix[i][j]);
        }
    }
for (i=0;i<n;i++){
    for (j=0;j<n;j++){
        printf("%d ", matrix[i][j]);
        }
     printf("\n");
    }
printf("\n");
marshal(matrix, n);
for (i=0;i<n;i++){
    for (j=0;j<n;j++){
        printf("%d ", matrix[i][j]);
        }
     printf("\n");
    }
return 0;
}
