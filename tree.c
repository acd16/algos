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

void search (leaf * l, int val)
{
if (l == NULL)
    printf ("not found\n");
else if (val == l->data) printf("found it!!!\n");
else if (val < l->data) search (l->left, val);
else if (val > l->data) search (l->right, val);
}

void main ()
{
leaf * l;
insert(&l, 5);
insert(&l, 2);
insert(&l, 7);
insert(&l, 1);
insert(&l, 9);
search (l, 1);
}
