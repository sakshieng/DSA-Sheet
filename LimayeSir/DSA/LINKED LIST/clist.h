#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct clist
{
    NODE *st;
}CLIST;

void init(CLIST *t)
{
    t->st=NULL;
}

// func to create new node
NODE *createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

// func to add new node at end
void addEnd(CLIST *t,int d)
{
    NODE *a=createNode(d),*b=t->st;
    if(t->st == NULL)
        a->next=a;
    else
    {
    a->next=b->next;
    b->next=a;
    }    
    t->st=a;   
}

// func to add new node at begin
void addBegin(CLIST *t,int d)
{
    NODE *a=createNode(d),*b;
    if(t->st == NULL)
    {
        t->st=a;
        a->next=a;
    }
    else
    {
        b=t->st;
        a->next=b->next;
        b->next=a;
    }  
}

// func to delete first node from list
void delFirst(CLIST *t)
{
    NODE *a=t->st,*b;
    if(t->st == NULL)
        return;
    b->next=a;
    if(a->next==a)//only one node
        t->st=a;
    else
    {
        a->next=b->next;
        free(b);
    }            
}

// func to delete last node from list
// traversing requires
void delLast(CLIST *t)
{
    NODE *a=t->st,*b;
    if(t->st == NULL)
        return;
    b=a->next;
    if(a->next==a)        
        t->st=NULL;
    else
    {
        while(b->next!=a)
        {
            b=b->next;
            b->next=a->next;
            t->st=b;
        }
    }    
    free(a);    
}

// func to display list
void display(CLIST *t)
{
    NODE *a=t->st;
    if(t->st == NULL)
        return;
    a=a->next;
    printf("\nData:\n");
    do
    {
        printf("%4d",a->data);
        if(a==t->st)
            break;
        a=a->next;            
    } while (1);
     return ;       
}
void main()
{
    CLIST p;
    int opt,d;
    
    while(1)
    {
        printf("\nMENU\n1.add at end\n2.add at begin\n3.display\n4.delete first node\n5.delete last node\n6.exit\nopt:");
        scanf("%d",&opt);
        if(opt>5)
        break;
        switch(opt)
        {
            case 1:
                    printf("\nenter data :\n");
                    scanf("%d",&d);
                    addEnd(&p,d);
                    break;
            case 2:
                    printf("\nenter data :\n");
                    scanf("%d",&d);
                    addBegin(&p,d);
                    break;
            case 3:
                    display(&p);
                    break;
            case 4:
                    delFirst(&p);
                    break;
            case 5:
                    delLast(&p);
                    break;
       }
    }
}