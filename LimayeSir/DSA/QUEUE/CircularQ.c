#include <stdio.h>
#include <stdlib.h>
#define M 5
// Code by Sakshi:

typedef struct queue
{
    int fr, rr;
    int arr[M];
} CQ;

void init(CQ *t)
{
    int i = 0;
    while (i < M)
    {
        t->arr[i] = -1;
        i++;
    }
    t->rr = t->fr = M - 1;
}

int cnt(CQ *t)
{
    int i = 0, cnt = 0;
    while (i < M)
    {
        if (t->arr[i] == -1)
            cnt++;
        i++;
    }
    return cnt;
}

void insert(CQ *t, int d)
{
    // cnt jr M asel tr sglikde flag asnar so overflow yenar
    if (cnt(t) == 0)
    {
        printf("\nOverflow");
        return;
    }
    if (t->rr == M - 1)
    {
        t->rr = 0;
    }
    else
    {
        t->rr++;
    }
    t->arr[t->rr] = d;
}

void remque(CQ *t)
{
    if (cnt(t) == M)
    {
        printf("\nUnderflow");
        return;
    }
    if (t->fr == M - 1)
        t->fr = 0;
    else
        t->fr++;
    t->arr[t->fr] = -1;
}

void display(CQ *t)
{
    int i = t->fr + 1;
    if (cnt(t) == M)
    {
        printf("\nEmpty queue");
        return;
    }
    if (t->fr < t->rr)
    {
        for (int i = 0; i <= t->rr; ++i)
        {
            printf("%4d", t->arr[i]);
        }
    }
    else
    {
        for (int i = t->fr + 1; i < M; ++i)
        {
            printf("%4d", t->arr[i]);
        }
        for (i = 0; i < t->rr; ++i)
        {
            printf("%4d", t->arr[i]);
        }
    }
}
// this is an integer array
int main()
{
    CQ p;
    init(&p);
    int opt, d;
    while (1)
    {
        printf("\nMenu\n1.Insert\n2.Remove\n3.Display\n4.Exit\nOption:");
        scanf("%4d", &d);
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            printf("\nDada:\n");
            scanf("%d", &d);
            insert(&p, d);
            break;
        case 2:
            remque(&p);
            break;
        case 3:
            display(&p);
            break;
        }
    }
    return 0;
}