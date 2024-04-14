#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
typedef struct slist
{
    NODE *st;
    int cnt;//count no.of nodes gets incremented or decremented not need to triverse in case of count
}SLIST;//data type
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//function to retrieve last node
NODE *getLastNode(NODE *a)
{
    while(a->next!=NULL)
        a=a->next;
    return a;
}
//function to init SLIST
void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;//list is empty no.of nodes=0
}
//function to add new node at end
void addEnd(SLIST *t,int d)
{
    NODE *a,*b;
    a=createNode(d);
    if(t->st==NULL)
        t->st=a;
    else
    {
        b=getLastNode(t->st);
        b->next=a;
    }
    t->cnt=t->cnt+1;
}
//function to add new node at begin
void addBeg(SLIST *t,int d)
{
    NODE *a=createNode(d);
    a->next=t->st;
    t->st=a;
    t->cnt=t->cnt+1;
}
//function to display list data
void display(SLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
        printf("\nempty list");
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
//function to compute data sum
int sum(SLIST *t)
{
    NODE *a=t->st;
    int tot=0;
    while(a!=NULL)
    {
        tot=tot+a->data;
        a=a->next;
    }
    return tot;
}
//function to find max data from slist
int findMax(SLIST *p)
{
    NODE *a=p->st;
    int max=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data>max)
            max=a->data;
    }
    return max;//call from main
}
//function to find min data from slist
int findMin(SLIST *p)
{
    NODE *a=p->st;
    int min=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data<min)
            min=a->data;
    }
    return min;
}
//function to delete first node from list
void delFirst(SLIST *p)
{
    NODE *a=p->st;
    if(a==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    p->st=a->next;
    free(a);
    p->cnt=p->cnt-1;
    return;
}
//function to delete last node from list
void delLast(SLIST *p)
{
    NODE *a=p->st,*b;
    if(a==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    if(a->next==NULL)
        p->st=NULL;
    else
    {
        while(a->next!=NULL)
        {
            b=a;
            a=a->next;
        }
        b->next=NULL;
    }
    free(a);
    p->cnt=p->cnt-1;
}
//fuction to delete all nodes from list
//void delAll(SLIST *p)
//{
  //  while(p->st!=NULL)
    //    delFirst(p);
//}
void delAll(SLIST *p)
{
    NODE *a=p->st,*b;
    while(a!=NULL)
    {
        b=a;
        a=a->next;
        free(b);
    }
    p->st=a;
    p->cnt=0;
}

//function to display list in reverse order
void revDisplay(NODE *a)
{
    if(a==NULL)
        return;
    revDisplay(a->next);
    printf("%4d",a->data);
}
//function to reverse whole list
void revList(SLIST *p)
{
    NODE *a=NULL,*b=p->st,*c;
    while(b!=NULL)
    {
        c=b->next;
        b->next=a;
        a=b;
        b=c;
    }
    p->st=a;
}
//count odd data nodes
int oddCount(SLIST *t)
{
    int cnt=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        cnt+=(a->data%2);
        a=a->next;
    }
    return cnt;
}
//count even data nodes
int evenCount(SLIST *t)
{
    int cnt=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(a->data%2==0)
            cnt++;
        a=a->next;
    }
    return cnt;
}
//function to display odd position nodes
void displayOddNodes(SLIST *t)
{
    int i=1;
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(i%2)
            printf("%4d",a->data);
        a=a->next;
    }
}
//function to display even position nodes
void displayEvenNodes(SLIST *t)
{
    int i=1;
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(i%2==0)
            printf("%4d",a->data);
        a=a->next;
    }
}
void sumA(SLIST *p)
{
    int val;
    NODE *a=p->st,*b,*c;
    while(a!=NULL)
    {
        b=a->next;
        if(b==NULL)
            break;
        val=a->data+b->data;
        c=createNode(val);
        c->next=b->next;
        b->next=c;
        a=c->next;
        p->cnt;

    }
}
void sumB(SLIST *p)
{
    int val;
    NODE *a=p->st,*b,*c,*tmp;
    while(a!=NULL)
    {
        b=a->next;
        if(b==NULL)
            break;
        val=a->data+b->data;
        c=createNode(val);
        if(a==p->st)
            p->st;
        else
            tmp->next=c;
            a=b->next;
            p->cnt++;

}
}
//function to delete i th position node from list
void deliNode(SLIST *p,int pos)
{
    NODE *a=p->st,*b,*c;
    int i=1;
    if(pos<1||pos>p->cnt)
        return;
    if(pos==1)
        delFirst(p);
    else
    {
        if(pos==p->cnt)
            delLast(p);
        else
        {
            while(i<pos)
            {
                b=a;
                a=a->next;
                i++;
            }
            c=a->next;
            b->next=c;
            free(a);
            p->cnt--;
        }
    }
}
//function to insert new node before i th position
void insertB(SLIST *p,int pos,int d)
{
    NODE *a=p->st,*b,*c;
    int i=1;
    if(pos<1||pos>p->cnt)
        return;
    if(pos==1)
        addBeg(p,d);
    else
    {
        while(i<pos)
        {
            b=a;
            a=a->next;
            i++;
        }
        c=createNode(d);
        b->next=c;
        c->next=a;
        p->cnt++;
    }
}
//funcion to insert new node after ith pos
 void insertA(SLIST *p,int pos,int d)
{
    NODE *a=p->st,*b,*c;
    int i=1;
    if(pos<1||pos>p->cnt)
        return;
    if(pos==1)
        addEnd(p,d);
    else
    {
        while(i<=pos)
        {
            b=a;
            a=a->next;
            i++;
        }
        c=createNode(d);
        b->next=c;
        c->next=a;
        p->cnt++;
    }
}
//function to search
NODE *search(SLIST *p,int val)
{
    NODE *a=p->st;
    while(a!=NULL)
    {
        if(a->data==val)
            break;
        a=a->next;
    }
    return a;
}
void findRepl(SLIST *p,int sv,int rv)
{
    NODE *a=p->st;
    while(a!=NULL)
    {
        if(a->data==sv)
            a->data=rv;
        a=a->next;
    }
    return;
}
SLIST copyList(SLIST *t)
{
    SLIST b;
    NODE *a=t->st;
    init(&b);
    while(a!=NULL)
    {
        addEnd(&b,a->data);
        a=a->next;
    }
    return b;
}
SLIST reversecopy(SLIST *t)
{
    SLIST b;
    NODE *a=t->st;
    init(&b);
    while(a!=NULL)
    {
        addBeg(&b,a->data);
        a=a->next;
    }
    return b;
}






#endif // SLIST_H_INCLUDED
