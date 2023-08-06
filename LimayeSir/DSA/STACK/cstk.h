#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
} STK;

void init(STK *t)
{
    t->top = NULL;
}

NODE *createNode(char d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

void push(STK *t, char d)
{
    NODE *a = createNode(d);
    a->next = t->top;
    t->top = a;
}

void pop(STK *t)
{
    NODE *a = t->top;
    if (t->top == NULL)
        printf("\nUnderflow");
    else
    {
        t->top = a->next;
        free(a);
    }
}

char stackTop(STK *t)
{
    NODE *a = t->top;
    return a->data;
    // if (t->top == NULL)
    //     printf("\nEmpty stack");
    // else
    //     printf("\nStack top:%c", a->data);
}

void display(STK *t)
{
    NODE *a = t->top;
    if (t->top == NULL)
        printf("\nEmpty stack");
    else
    {
        printf("\nStack data:\n");
        while (a != NULL)
        {
            printf("%c", a->data);
            a = a->next;
        }
    }
}

int isEmpty(STK *t)
{
    return (t->top == NULL);
}