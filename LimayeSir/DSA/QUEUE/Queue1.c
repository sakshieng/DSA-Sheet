#include <stdio.h>
#include <stdlib.h>
#define M 5
// Code by Sakshi:
//  Implementation of queue using array
typedef struct queue
{
    int arr[M];
    int fr, rr;
} Q;

void init(Q *t)
{
    t->fr = 0;
    t->rr = -1;
}

int isEmpty(Q *t)
{
    return t->rr < t->fr;
}

int isFull(Q *t)
{
    return t->rr == M - 1;
}

void insert(Q *t, int d)
{
    if (isFull(t))
    {
        printf("\nOverflow");
    }
    else
    {
        t->rr++;
        t->arr[t->rr] = d;
    }
}

void remque(Q *t)
{
    if (isEmpty(t))
    {
        printf("\nUnderflow");
    }
    else
    {
        t->fr++;
    }
}

void display(Q *t)
{
    int i = t->fr;
    if (isEmpty(t))
    {
        printf("\nEmpty queue");
    }
    else
    {
        printf("\nQueue Data\n");
        while (i <= t->rr)
        {
            printf("%4d", t->arr[i]);
            i++;
        }
    }
    return;
}

int main()
{
    Q p;
    init(&p);
    int opt, d;
    while (1)
    {
        printf("\nMenu\n1.insert\n2.remove\n3.display\n4.exit\nOption:");
        scanf("%d", &opt);
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            printf("\nData:");
            scanf("%d", &d);
            insert(&p, d);
            break;
        case 2:
            // no need to ask which data is to be removed as it automatically removes rear element when we call this func
            remque(&p);
            break;
        case 3:
            display(&p);
            break;
        }
    }
    return 0;
}