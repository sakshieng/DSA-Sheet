// Code by Sakshi:
#include <stdio.h>
#include <stdlib.h>
// doubly linked list

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;

typedef struct DoubleList
{
    NODE *st; // ptr to first node
    NODE *ed; // ptr to last node
} DLIST;

// func to create node
NODE *createNode(int d)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->prev = a->next = NULL;
    return a;
}

void init(DLIST *t)
{
    t->st = t->ed = NULL;
}

// func to add node at end
void addEnd(DLIST *t, int d)
{
    NODE *a = createNode(d);
    NODE *b = t->ed;
    if (t->st == NULL)
        t->st = a;
    else
    {
        b->next = a;
        a->prev = b;
    }
    t->ed = a;
}

// func to display list from begin to end
void displayLR(DLIST *t)
{
    NODE *a = t->st;
    if (t->st == NULL)
        printf("Empty list\n");
    else
    {
        printf("\nData:");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}
// end to begin func to display list from end to begin
void displayRL(DLIST *t)
{
    NODE *a = t->ed;
    if (t->ed == NULL)
        printf("Empty list\n");
    else
    {
        printf("\nData\n");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->prev;
        }
    }
}

// delete first node from list
void deleteFirst(DLIST *t)
{
    NODE *a = t->st, *b;
    if (t->st == NULL)
        return;
    if (t->st == t->ed)
        t->st = t->ed = NULL;
    // for one node in LL
    else
    {
        b = a->next;
        b->prev = NULL;
        t->st = b;
    }
    free(a);
}

// delete last node from list
void deleteLast(DLIST *t)
{
    NODE *a = t->ed, *b;
    if (t->st == NULL)
        return;
    if (t->st == t->ed)
        t->st = t->ed = NULL;
    else
    {
        b = a->prev;
        b->next = NULL;
        t->ed = b;
    }
    free(a);
}

// func to delete i^th node from list
void deliNode(DLIST *t, int pos)
{
    NODE *a = t->st, *b, *c;
    int i = 1;
    if (t->st == NULL)
        return;
    if (pos < 1)
    {
        printf("Invalid position to delete");
        return;
    }
    if (pos == 1)
        deleteFirst(t);
    else
    {
        while (i < pos && a != NULL)
        {
            b = a;
            a = a->next;
            i++;
        }
        if (a == NULL) // invalid
        {
            printf("Invalid position to delete node from list");
            return;
        }
        if (a->next == NULL)
            deleteLast(t);
        else
        {
            c = a->next;
            b->next = c;
            c->next = c;
            c->prev = b;
            free(a);
        }
    }
}

// insert new node before i^th position
void insertA(DLIST *p, int pos, int d)
{
    NODE *a, *b, *c;
    int i = 1;
    if (pos < 1)

        c = createNode(d);
    b->next = c;
    c->next = b;
    b->next = a;
    a->next = b;
}

// insert new node after i^th position
void insertA(DLIST *t, int pos, int d)
{
    NODE *a, *b, *c;
    int i = 1;
    // p.st==NULL empty list
    if (pos < 1)
        return;
    int i = 1;
    while (i <= pos && a != NULL)
    {
        b = a;
        a = a->next;
        i++;
        if (i < pos)
            printf("Invalid position");
        c = createNode(d);
        c->prev = b;
        b->next = c;
        if (a != NULL)
        {
            c->next = a;
            a->prev = c;
            // intermediate request
        }
        else
        {
            t->ed = c;
        }
    }
}

void main()
{
    NODE *a, *b, *c;
    DLIST *t;
    // 9 items
    int pos, d;
    int opt;
    switch (opt)
    {
    case 1:
        printf("\nNode position to insert after: ");
        scanf("%d", &pos);
        printf("\nEnter data:");
        scanf("%d", &d);
        insertA(&t, pos, d);
    }
}
// command prompt DoublyLL che example as link is maintained up and down
// getch getche getchar 3 methods used to input a single character
//password input