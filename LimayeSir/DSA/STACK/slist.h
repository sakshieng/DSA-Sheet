#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct slist
{
    NODE *st; // head node pointer
    int cnt;  // no of nodes in list
} SLIST;

NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

// func to retrieve last node
// jya list cha last node pahije tycha first node ite pass krycha
NODE *getLastNode(NODE *a)
{
    while (NULL != a->next)
    {
        a = a->next;
        return a;
    }
}

// func to initialize slist
void init(SLIST *t)
{
    t->st = NULL;
    // t holds address of slist
    t->cnt = 0;
}

// func to add new node at begin
void addBeg(SLIST *t, int d)
{
    NODE *a = createNode(d);
    a->next = t->st;
    t->st = a;
    t->cnt = t->cnt + 1;
}

// func to add new node at end
void addEnd(SLIST *t, int d)
{
    NODE *a = createNode(d);
    a->next = t->st;
}

// func to display list data
void display(SLIST *t)
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

// func to display sum of nodes
int sum(SLIST *t)
{
    NODE *a = t->st;
    int tot = 0;
    while (a != NULL)
    {
        tot = tot + a->data;
        a = a->next;
    }
    return tot;
}

// func to find max data from SLIST
int findMax(SLIST *p)
{
    NODE *a = p->st;
    int max = a->data;
    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data > max)
            max = a->data;
    }
    return max;
}

// func to find min data from SLIST
int findMin(SLIST *p)
{
    NODE *a = p->st;
    int min = a->data;
    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data < min)
            min = a->data;
    }
    return min;
}

// func to delete first node from the SLIST
void delFirst(SLIST *p)
{
    NODE *a = p->st;
    if (a == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    p->st = a->next;
    free(a);
    p->cnt = p->cnt - 1;
    return;
}

// func to delete last node from list
void delLast(SLIST *p)
{
    NODE *a = p->st, *b;
    if (a == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    else
    {
        if (a->next == NULL)
            p->st = NULL;
        else
        {
            while (a->next != NULL)
            {
                b = a;
                a = a->next;
            }
            b->next = NULL;
        }
    }
    free(a);
    p->cnt = p->cnt - 1;
}

// func to delete all nodes from list
// void delAll(SLIST *p)
// {
//     while (p->st != NULL)
//         delFirst(p);
//     // here func is called 100 times
// }
// efficient way
void delAll(SLIST *p)
{
    NODE *a = p->st, *b;
    while (a != NULL)
    {
        b = a;
        a = a->next;
        free(b);
    }
    p->st = a;
    p->cnt = 0;
}

// func to display func in reverse order
void revDisplay(NODE *a)
{
    // recursive way callinf func itself thr func end condition for it is a==NULL
    if (a == NULL)
        return;
    revDisplay(a->next);
    printf("%4d", a->data);
    // LIFO the call of a==400 is going first in stack :: a==NULL paryant return hot janar 400 300 200 100 NULL and print accordi
}

// func to reverse whole list
void revList(SLIST *p)
{
    NODE *a = NULL, *b = p->st, *c;
    while (b != NULL)
    {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    p->st = a;
}

// count odd data nodes
int oddCount(SLIST *t)
{
    int cnt = 0;
    NODE *a = t->st;
    while (a != NULL)
    {
        cnt += (a->data % 2);
        a = a->next;
    }
    return cnt;
}

// count even data nodes
int evenCount(SLIST *t)
{
    int cnt = 0;
    NODE *a = t->st;
    while (a != NULL)
    {
        if (a->data % 2 == 0)
            cnt++;
        a = a->next;
    }
    return cnt;
}

// function to display odd position nodes
void displayOddNodes(SLIST *t)
{
    int i = 1;
    NODE *a = t->st;
    while (a != NULL)
    {
        if (i % 2)
            printf("%4d", a->data);
        a = a->next;
    }
}

// function to display even position nodes
void displayEvenNodes(SLIST *t)
{
    int i = 1;
    NODE *a = t->st;
    while (a != NULL)
    {
        if (i % 2 == 0)
            printf("%4d", a->data);
        a = a->next;
    }
}

// toh special wala que 1 2 6 4 5 4-->1 2 3 6 4 10 5 4 9
void sumA(SLIST *p)
{
    int val;
    NODE *a = p->st, *b, *c;
    while (a != NULL)
    {
        b = a->next;
        if (b == NULL)
            break;
        val = a->data + b->data;
        c = createNode(val);
        c->next = b->next;
        b->next = c;
        a = c->next;
        p->cnt++;
    }
}

// by temperory variable
void sumB(SLIST *p)
{
    int val;
    NODE *a = p->st, *b, *c, *tmp;
    while (a != NULL)
    {
        b = a->next;
        if (b == NULL)
            break;
        val = a->data + b->data;
        c = createNode(val);
        if (a == p->st)
            p->st;
        else
            tmp->next = c;
        a = b->next;
        p->cnt++;
    }
}

// func to delete i^th position from the list
void deliNode(SLIST *p, int pos)
{
    NODE *a = p->st, *b, *c;
    int i = 1;
    if (pos > p->cnt || pos < 1)
        return; // case of empty list
    if (pos == 1)
        delFirst(p);
    else
    {
        if (pos == p->cnt)
            delLast(p);
        else
        {
            while (i < pos)
            {
                b = a;
                a = a->next;
                i++;
            }
            c = a->next;
            b->next = c;
            free(a);
            p->cnt--; // jri p->cnt=0 asel tri chalte as delfirst mdhe te pahile jail
        }
    }
}

// func to insert new node before i^th position
void insertB(SLIST *p, int pos, int d)
{
    NODE *a = p->st, *b, *c;
    int i = 1;
    if (pos < 1 || pos > p->cnt)
        return;
    if (pos == 1)
        addBeg(p, d);
    else
    {
        while (i < pos)
        {
            b = a;
            a = a->next;
            i++;
        }
        c = createNode(d);
        b->next = c;
        c->next = a;
        p->cnt++;
    }
}

// func to insert new node before i^th position
void insertA(SLIST *p, int pos, int d)
{
    NODE *a = p->st, *b, *c;
    int i = 1;
    if (pos < 1 || pos > p->cnt)
        return;
    if (pos == p->cnt)
        addEnd(p, d);
    else
    {
        while (i <= pos)
        {
            b = a;
            a = a->next;
            i++;
        }
        c = createNode(d);
        b->next = c;
        c->next = a;
        p->cnt++;
    }
}

// func to search a value from the specified SLIST
//   if found return address i.e. NODE * is returning address
NODE *search(SLIST *p, int val)
{
    NODE *a = p->st;
    while (a != NULL)
    {
        if (a->data == val)
            break;
        a = a->next;
    }
    return a;
}

// func to implement find and replace
void findRepl(SLIST *p, int sv, int rv)
{
    NODE *a = p->st;
    while (a != NULL)
    {
        if (a->data == sv)
            a->data = rv;
        a = a->next;
    }
    return;
}

// copying one LL to another by calling addEnd func
// SLIST copyList(SLIST *t)
// {
//     SLIST b;
//     NODE *a = t->st;
//     init(&b);
//     while (a != NULL)
//     {
//         addEnd(&b, a->data);
//         a = a->next;
//     }
//     return b;
// }

// // another efficient way of copying
// SLIST copyList(SLIST *p)
// {
//     SLIST q;
//     NODE *a=p->st,*b,*c;
//     init(&q);
//     while (a!=NULL)
//     {
//         b=(NODE *)malloc(sizeof(NODE));
//         b->data=a->data;
//         b->next=NULL;
//         if(q.st==NULL)
//             q.st=b;
//         else
//         c->next=b;
//         c=b;
//         q.cnt++;
//         a=a->next;
//     }
//     return q;
// }

// copying one LL to another by calling addBeg func in reverse order
// SLIST reverseCopy(SLIST *t)
// {
//     SLIST b;
//     NODE *a = t->st;
//     init(&b);
//     while (a != NULL)
//     {
//         addBeg(&b, a->data);
//         a = a->next;
//     }
//     return b;
// }

// another efficient way
SLIST reverseCopy(SLIST *p)
{
    SLIST q;
    NODE *a = p->st, *b;
    init(&q);
    while (a != NULL)
    {
        b = createNode(a->data);
        b->next = q.st;
        q.st = b;
        q.cnt++;
        a = a->next;
    }
    return q;
}

// func to copy list
void copyList(SLIST *d, SLIST *s)
{
    NODE *a = NULL;
    NODE *b = s->st;
    NODE *c;
    if (s->st == NULL)
        return;
    if (d->st != NULL)
        delAll(d);
    while (b != NULL)
    {
        c = createNode(b->data);
        if (d->st)
            d->st = c;
        else
        {
            a->next = c;
            a = c;
            b = b->next;
            d->cnt++;
        }
    }
}
// func to copy list data to the text file list.txt
// putw(data,file)
void toFile(SLIST *p)
{
    FILE *f1;
    NODE *a = p->st;
    int data;
    f1 = fopen("slist.txt", "w");
    while (a != NULL)
    {
        data = a->data;
        putw(data, f1);
        a = a->next;
    }
    fclose(f1);
}

// func to built slist from text file slist.txt
void fromFile(SLIST *p)
{
    FILE *f1;
    NODE *a, *b;
    int data;
    f1 = fopen("slist.txt", "r");
    if (f1 == NULL)
    {
        printf("\nFile not found");
        return;
    }
    // if file exists and there are nodes in list
    if (f1 == NULL)
    {
        printf("\nFile not found");
        return;
    }
    // file poniter jithe present ahe tithe
    // end of file asel tr break kryche
    // as we are reading data thr file no need of a=a->next
    if (p->st != NULL)
        delAll(p);
    while (1)
    {
        data = getw(f1);
        if (feof(f1))
            break;
        a = createNode(data);
        if (p->st == NULL)
            p->st = a;
        else
            b->next = a;
        b = a;
        p->cnt++;
    }
    fclose(f1);
}

// func to copy data from array to list
//  i.e.func to built SLIST from array
//  cnt no of elements sathi memory allocation
//  func should return base address of an array returning type int *
void fromArray(SLIST *p, int *x, int n)
{
    int data, i = 0;
    NODE *a, *b;
    // head pointer mdhe st chi value null nhiye i.e. node exists in list
    // or if(p->cnt>0)
    if (p->cnt == NULL)
        delAll(p);
    while (i < n)
    {
        data = x[i];
        a = createNode(data);
        if (p->st == NULL)
            p->st = a;
        else
            b->next = a;
        b = a;
        p->cnt++;
        i++;
    }
    // x is an array
    // *x+i==x[i]
    // b always refering to last node
}

// func to copy list data to an array
int *listToArray(SLIST *p)
{
    int *a = (int *)malloc(p->cnt * sizeof(int));
    int i = 0;
    NODE *b = p->st;
    while (b != NULL)
    {
        a[i++] = b->data;
        b = b->next;
    }
    return a;
}

// func to append
void appendList(SLIST *d, SLIST *s)
{
    NODE *a = NULL;
    NODE *b = d->st;
    NODE *c;
    if (s->st != NULL)
        return;
        // destination string empty ahe
    if (d->st != NULL)
        a = getLastNode(d->st);
    while (b != NULL)
    {
        c = createNode(b->data);
        if (d->st)
            d->st = c;
        else
        {
            a->next = c;
            a = c;
            b = b->next;
            d->cnt++;
        }
    }
}
