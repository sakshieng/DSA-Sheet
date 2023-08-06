#include <stdio.h>
#include <stdlib.h>
#define M 10
// Code by Sakshi:

typedef struct Q
{
    int arr[M];
    int fr, rr;
} PQ;

void init(PQ *t)
{
    t->fr = 0;
    t->rr = -1;
}

void insert(PQ *t, int d)
{
    int i;
    if (t->rr == M - 1)
        printf("\nOverflow");
    else
    {
        for (i = t->rr; i >= 0 && d < t->arr[i]; i--)
            t->arr[i + 1] = t->arr[i];
        t->arr[i + 1] = d;
        t->rr++;
    }
}

void display(PQ *t)
{
    int i = t->fr;
    if (t->rr < t->fr)
        printf("\nEmpty queue");
    else
    {
        for (i = t->fr;; ++i)
            printf("%4d", t->arr[i]);
    }
}

void delete(PQ *t) 
{
    int i=
}
int main()
{
    PQ t;
    init(&t);
    int opt,d;
    printf("\nMenu:\n1.Insert2.Display\n3.Delete\n4.Exit\nOption:");
    scanf("%d", &opt);
    while (1)
    {
        if (opt > 4)
            break;
        switch (opt)
        {
        case 1:
        insert(&t,d);
        scanf("%d",&d);
        break;
        case 2:
        display(&t);
        break;
        case 3:
        
        }
    }

    return 0;
}