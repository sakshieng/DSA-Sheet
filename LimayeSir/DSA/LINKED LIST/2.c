#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
// linked list creation using local head pointer
// we can use more than one linked list here-->is is dynamic in nature
typedef struct node
// it is self referential node
{
    int data;
    struct node *next;
} NODE;

// func to create NODE
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE)); // dynamic memory allocation
    a->data = d;
    a->next = NULL;
    return a;
}
// local head pointer have only scope to main()
// pass by reference func call
// if we have to alter s1 pointer use above one if not then use pass by value

// func to initialize local pointer
// s1 cha address p la ahe
void init(NODE **p)
{
    *p = NULL;
}
NODE *getLastNode(NODE **p)
{
    NODE *a = *p;
    while (a->next != NULL)
    {
        a = a->next;
        return a;
    }
}
// func to add new node at end
// func call by passing value as we are passing address of p getLastNode la a pasun chya LL cha last node cha address milel
void addEnd(NODE **p, int d)
{
    NODE *a, *b;
    a = createNode(d);
    if (*p == NULL)
    {
        *p = a;
    }
    else
    {
        b = getLastNode(p);
        b->next = a;
    }
}
// add at begin
// **p-->complete node of block of bytes
void addBeg(NODE **p, int d)
{
    NODE *a;
    a = createNode(d);
    a->next = *p;
    *p = a;
}
// func to display
void display(NODE **p)
{
    NODE *a = *p;
    if (a == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}
/*
void totalCount(NODE **p, int d)
{
    NODE *a = *p;
    if (a == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        int cnt = 0;
        printf("\nData");
        while (a != NULL)
        {
            printf("%d", a->data);
            cnt++;
            a = a->next;
        }
        printf("%d\n", cnt);
    }
}
*/

// func to count no of nodes
int count(NODE **p)
{
    int tot=0;
    NODE *a=*p;
    while(a!=NULL)
    {
        tot++;
        a=a->next;
    }
    return tot;
}

// func to create data sum
int sum(NODE **p)
{
    int sum = 0;
    NODE *a = *p;
    while (a != NULL)
    {
        sum += a->data;
        a = a->next;
    }
    return sum;
}

// find maximum node data
int findmax(NODE **p)
{
    int max=0;
    NODE *a=*p;
    while (a!=NULL)
    {
        if(a==*p)
            max=a->data;
        else
        {
            if(a->data > max)
                max=a->data;
        }            
        a=a->next;
    }
    return max;
}

// find minimum node data
int findmin(NODE **p)
{
    int min=0;
    NODE *a=*p;
    while (a!=NULL)
    {
        if(a==*p)
            min=a->data;
        else
        {
            if(a->data < min)
                min=a->data;
        }            
        a=a->next;
    }
    return min;
}
void main()
{
    NODE *s1;
    int opt,d;
    init(&s1);
    while (1)
    {
        printf("\nMenu\n1.Add at end\n2.Add at beg\n3.Display\n4.Total Count\n5.Sum\n6.Exit\nOption:");
        scanf("%d", &opt);
        if (opt > 7)
            break;
        else
        {
            switch (opt)
            {
            case 1:
                printf("\nEnter data");
                scanf("%d", &d);
                addEnd(&s1, d);
                break;
            case 2:
                printf("\nEnter data");
                scanf("%d", &d);
                addBeg(&s1, d);
                break;
            case 3:
                display(&s1);
                break;
            case 4:
                if (s1 == NULL)
                    printf("\nList Empty");
                else
                    printf("Nodes%d\n", count(&s1));
                break;
            case 5:
                printf("%d\n", (&s1));
                break;                           
            }
        }
    }
}