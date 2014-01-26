#include "tree.h"

void insert(leaf ** l, int val)
{
if (*l == NULL)
    {
    *l = malloc (sizeof (leaf));
    (*l)->data = val;
    (*l)->left = NULL;    
    (*l)->right = NULL;    
    }
else if (val < ((*l)->data)) insert(&(*l)->left, val);
else if (val > ((*l)->data)) insert(&(*l)->right, val);
}

leaf * search (leaf * l, int val)
{
if (l == NULL)
    printf ("not found\n");
else if (val == l->data) {printf("found it!!!\n"); return l;}
else if (val < l->data) search (l->left, val);
else if (val > l->data) search (l->right, val);
}

void postOrder(leaf * l)
{
if(l != NULL)
{
postOrder(l->left);
postOrder(l->right);
printf("%d ", l->data);
}
}

void inOrder(leaf * l)
{
if(l != NULL)
{
inOrder(l->left);
printf("%d ", l->data);
inOrder(l->right);
}
}

void min(leaf *l)
{
if(l->left != NULL)
    {
    min (l->left);
    }
else
    {
    printf("min is %d\n", l->data);
    }
}

void max(leaf *l)
{
if(l->right != NULL)
    {
    max (l->right);
    }
else
    {
    printf("min is %d\n", l->data);
    }
}

int getCount(leaf * l)
{
if (l != NULL)
    {
    printf("in with %d\n",l->data); 
    return (getCount (l->left) + getCount (l->right) + 1);
    }
else
    return 0;
}

int main ()
{
leaf * l;
insert(&l, 20);
insert(&l, 13);
insert(&l, 9);
insert(&l, 15);
insert(&l, 67);
insert(&l, 75);
insert(&l, 33);
insert(&l, 25);
insert(&l, 24);
//insert(&l, 10);
inOrder(l);
printf("\n");
postOrder(l);
printf("\n");
min(l);
max(l);
printf ("count is %d\n", getCount(l));
return 0;
}
