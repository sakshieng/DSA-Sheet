#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

}NODE;
NODE *st=NULL;
//fn to create node
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE*)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//fn to retrieve last node address
NODE* getLastNode()//independent function
{
    NODE *a=st;
    while(a->next!=NULL)
        a=a->next;
    return a;// a is last node

}
//function to add new node at end
void addEnd(int d)
{
    NODE *a,*b;
    a=createNode(d);
    if(st==NULL)
        st=a;
    else
    {
        b=getLastNode();
        b->next=a;
    }
}
//function to add new node at begin
void addBeg(int d)
{
    NODE *a;
    a=createNode(d);
    a->next=st;
    st=a;
}
//function to display list data
void display()
{
    NODE *a=st;
    if(st==NULL)
        printf("\nEmpty list");
    else
    {
        printf("\nData\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}
void main()
{
    int opt,d;
    while(1)
    {
        printf("\nsingle linked list\nMenu\n1.Add end\n2.Add beg\n3.display\n4.Exit\noption:");
        scanf("%d",&opt);
        if(opt>3)
                break;
        switch(opt)
        {
        case 1:
            printf("\nAdd end Data:");
            scanf("%d",&d);
            addEnd(d);
            break;
        case 2:
            printf("\nAdd beg Data:");
            scanf("%d",&d);
            addBeg(d);
            break;
        case 3:
            display();
        }
    }
}

