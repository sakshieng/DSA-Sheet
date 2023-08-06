#include<stdio.h>
#include<stdlib.h>

//linked list using local head
typedef struct node
{
    int data;
    struct node *next;
}NODE;
//function to create node
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//function to initialize
void init(NODE**p)
{
    *p=NULL;
}
NODE *getLastNode(NODE **p)
{
    NODE *a=*p;
    while(a->next!=NULL)
        a=a->next;
    return a;
}
//function to add new node at end
void addEnd(NODE **p,int d)
{
    NODE *a=createNode(d),*b;
    if(*p==NULL) //if list is empty
        *p=a;
    else
    {
        b=getLastNode(p);
        b->next=a;
    }
}
//function to add new node at begin
void addBeg(NODE **p,int d)
{
    NODE *a=createNode(d);
    a->next=*p;
    *p=a;
}
//function to display list data
void display(NODE **p)
{
    NODE *a=*p;
    if(a==NULL)
        printf("\nEmpty list");
    else
    {
        printf("\nData:\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}
//function to compute sum
int sum(NODE **p)
{
    int tot=0;
    NODE *a=*p;
    while(a!=NULL)
    {
        tot+=a->data;
        a=a->next;
    }
    return tot;

}
//function to count no.of nodes
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
//find maximum
int findmax(NODE **p)
{
    int mx=0;
    NODE *a=*p;
    while(a!=NULL)
    {
        if(a==*p)
            mx=a->data;
        else
        {
            if(a->data>mx)
                mx=a->data;
        }
        a=a->next;

    }
    return mx;
}
//find minimum
int findmin(NODE **p)
{
    int mn=0;
    NODE *a=*p;
    while(a!=NULL)
    {
        if(a==*p)
            mn=a->data;
        else
        {
            if(a->data<mn)
                mn=a->data;
        }
        a=a->next;
    }
    return mn;
}





void main()
{
    NODE *s1;
    int opt,d;
    init(&s1);
    while(1)
    {
        printf("\nMenu\n1.Add at end\n2.Add at beg\n3.display\n4.sum\n5.count\n6.max\n7.min\nexit\noption:");
        scanf("%d",&opt);
        if(opt>7)
            break;
        switch(opt)
        {    
        case 1:
            printf("\nData:\n");
            scanf("%d",&d);
            addEnd(&s1,d);
            break;
        case 2:
            printf("\nData:\n");
            scanf("%d",&d);
            addBeg(&s1,d);
            break;
        case 3:
            display(&s1);
        case 4:
            printf("\nsum:%d",sum(&s1));
            break;
        case 5:
            if(s1==NULL)
                printf("\nEmpty list");
            else
                printf("\nNodes:%d",count(&s1));
            break;
        }
    }
}
