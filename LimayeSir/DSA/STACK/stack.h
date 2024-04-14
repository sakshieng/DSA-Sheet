
typedef struct node
{
    int data;
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

NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(int));
    a->data = d;
    a->next = NULL;
    return a;
}

void push(STK *t, int d)
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

void stackTop(STK *t)
{
    NODE *a = t->top;
    if (t->top == NULL)
        printf("\nEmpty stack");
    else
        printf("\nStack top:%d", a->data);
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
            printf("%4d", a->data);
            a = a->next;
        }
    }
}
