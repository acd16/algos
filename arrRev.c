#include <stdio.h>
void main ()
{
int a[6] = {1, 2, 3, 4, 5, 6}, i, temp, p, s;
s = sizeof(a)/sizeof(int);
p = s/2;
for (i=0;i<p;i++){
temp = a[i];
a[i] = a[(s-1)-i];
a[(s-1)-i] = temp;
}
for (i=0;i<s;i++){
printf("%d\n", a[i]);
}
}
