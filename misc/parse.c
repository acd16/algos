#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void tokenize (char ** line, char * token, int num)
{
printf ("%s", *line);
int i;
for (i=0;i<num;i++)
    {
    *line = strstr (*line, ":");
    printf ("%s\n", *line);
    (*line)++;
    }
*line = strtok (*line, ":");
}
void main ()
{
char *str = NULL, *temp = NULL;
str = malloc (30);
strcpy(str, "USB:HP:/deb/usb0/:2520");
printf ("%p %p\n", str, &str);
temp = str;
tokenize(&str, ":", 2);
printf("Final %s\n", str);
free (temp);
}
