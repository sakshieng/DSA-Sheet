#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
typedef struct node
// implementation using global head pointer
// it is self referential node
{
    int data;
    struct node *next;
}NODE;
NODE *st=NULL;//head pointer
// func to create NODE
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));//dynamic memory allocation
    a->data=d;
    a->next=NULL;
    return a;
}
//func to retrieve last node address
// st alter for deletion begin,added begin,deletion complete list
NODE *getLastNode()
{
    NODE *a=st;
    while(a->next != NULL)//here we cant consider last node data
    {
        a=a->next;
        return a;
    }
// returning type is node pointer
}
// func to add new node at end
void addEnd(int d)
{
    NODE *a,*b;
    a=createNode(d);
    if(st==NULL)
    {
        st=a;
    }
    else
    {
        b=getLastNode();
        b->next=a;
    }
}
// func to add new node at beginning
void addBeg(int d)
{
    NODE *a;
    a=createNode(d);
    a->next=st;
    st=a;
}
// func to display list data
// declare traversal pointer a
void display()
{
    NODE *a=st;
    if(st==NULL)
        printf("\nEmpty List");
    else
    {
        printf("Data\n");
        while(a!=NULL){
        printf("%4d",a->data);
        // 30-->20-->10-->40
        a=a->next;
        }
    }        
}
int main()
{
   int opt,d;
   while(1)
   {
        printf("\nSingle Linked List\nMenu\n1.Add end\n2.Add beg\n3.Display\n4.Exit\nOption:");
        scanf("%d",&opt);
        if(opt>3)
        break;
        switch (opt)
        {
        case 1:
            printf("\nAdd End Data");
            scanf("%d",&d);
            addEnd(d);
            break;
        case 2:
            printf("\nAdd Beg Data");
            scanf("%d",&d);
            addBeg(d);
            break;
        case 3:
            display();            
        }
   }
   return 0;
}