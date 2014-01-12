#include<stdio.h>
int add (int a, int b)
{
return a+b;
}

int sub (int a, int b)
{
return a-b;
}

void main ()
{
int (*fp)(int, int) = NULL;
fp = &add;
printf ("op is %d\n", fp(1,2));
}
