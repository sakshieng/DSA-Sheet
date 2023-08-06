#include <stdio.h>
#include <stdlib.h>
// Code by Sakshi:

// array implementation of stack
#define M 5
typedef struct stack
{
    int top;
    int arr[M];
} STK;
void init(STK *t)
{
    t->top = -1;
}

// func to push element in stack
void push(STK *t, int d)
{
    if (t->top == M - 1)
        printf("\nOverflow");
    else
    {
        t->top++;
        t->arr[t->top];
    }
}

// func to pop element from stack
void pop(STK *t)
{
    if (t->top == -1)
        printf("\nUnderflow");
    else
    {
        t->top--;
    }
}

int isFull(STK *t)
{
    return t->top == M - 1;
}

int isEmpty(STK *t)
{
    return t->top == -1;
    // top element cha index -1 la initialize kelay so NULL nhi ghyche
}

void display(STK *t)
{
    int i = t->top;
    if (t->top == -1)
        printf("\nEmpty list");
    else
    {
        printf("\nData\n");
        while (i >= 0)
        {
            printf("%4d", t->arr[i]);
            i--;
        }
    }
}

int main()
{
    int opt, d;
    STK *p;
    init(&p);
    while (1)
    {
        printf("\nStack Menu:\n1.Push\n2.Pop\n3.Is Full\n4.Is Empty\n5.display\n6.Exit\nOption:");
        scanf("%d", &opt);
        if (opt > 5)
            break;
        switch (opt)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &d);
            push(&p, d);
            break;
        case 2:
            pop(&p);
            break;
        case 3:
            if (isFull(&p))
                printf("\nStack full");
            else
                printf("\nStack is not full");
            break;
        case 4:
            if (isEmpty(&p))
                printf("\nEmpty Stack");
            else
                printf("\nStack is not empty");
            break;
        case 5:
            display(&p);
            break;            
        }
    }
    return 0;
}