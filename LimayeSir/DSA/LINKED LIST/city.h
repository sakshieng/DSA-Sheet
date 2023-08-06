#include<stdio.h>
#include<stdlib.h>
//Code by Sakshi:

typedef struct node
{
    int data;
    char name[15];
    struct node *next;
}NODE;

typedef struct city
{
    NODE *st; 
    int cnt;
}CITY;

NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}
NODE *getLastNode(NODE *a)
{
    while (NULL != a->next)
    {
        a = a->next;
        return a;
    }
}
void init(CITY *t) 
{
    t->st=NULL;
}

void addBeg(CITY *t, int d)
{
    NODE *a = createNode(d);
    a->next = t->st;
    t->st = a;
    t->cnt = t->cnt + 1;
}
void display(CITY *t)
{
    NODE *a = t->st;
    if (t->st == NULL)
        printf("\nEmpty list");
    else
    {
        printf("\nData");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}
