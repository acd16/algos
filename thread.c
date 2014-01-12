#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
int count = 0;

typedef struct da{
int i;
int j;
}data;

void * add(void * num)
{
int * i = (int*) num;
printf ("came in %d\n", *i);
pthread_mutex_lock(&lock);
count += *i;
pthread_mutex_unlock(&lock);
}

void main ()
{
pthread_t t[5];
int j = 1, i;
for (i = 0;i<5;i++)
    pthread_create(&t[i], NULL, add, (void*) &j);
    
for (i = 0;i<5;i++)
    pthread_join(t[i], NULL);

printf ("sum is %d\n" , count);
}
