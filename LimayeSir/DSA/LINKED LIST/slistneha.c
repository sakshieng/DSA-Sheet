//Node who's next part is null is last node
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
  int data; //it reserves 2 bytes
  struct node *next; //   It reserves 2 bytes
}NODE;

typedef struct slist // slist ha data type declare kelay
{
    NODE *st; //Head node pointer
    int cnt; //it counts no. of nodes as no. of nodes increases count increases and if we delete any node then count decreases
}SLIST;

NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

//Jevde slist type cha variable tevde linkedlist 
NODE *getLastNode(NODE *a) //*a means apan head node cha address pass kelay
{
    while(a->next!=NULL)
      a=a->next;
    return a;  
}

//Function to initialize slist
void init(SLIST *t) //t->st = 100 in this e.g.
{
    t->st = NULL;  // t holds the address of slist 
    t->cnt =0;
}

//function to add new node at end
void addEnd(SLIST *t,int d)
{
    NODE *a,*b;
    a = createNode(d);
    if(t->st==NULL)
     t->st=a;
    else
    {
        b=getLastNode(t->st);
        b->next=a;
    } 
    t->cnt = t->cnt + 1;
}

//Function to add new node at begin
void addBeg(SLIST *t,int d)
{
    NODE *a;
    a=createNode(d);
    a->next = t->st;
    t->st = a;
    t->cnt = t->cnt + 1;
}

//Function to display list data
void display(SLIST *t)
{
    NODE *a;
    a=t->st; 
    if(t->st == NULL)
       printf("\nEmpty list");
    else
    {
        printf("\nData : ");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }   
}

//Function to compute data sum
int sum(SLIST *t)
{
    NODE *a;
    a = t->st;
    int tot=0;
    while(a!=NULL)
    {
        tot = tot + a->data;
        a=a->next;
    }
    return tot;
}

//Function to find maximum of all the data from SLIST
int findMax(SLIST *t)
{
    NODE *a;
    a = t->st;
    int max;
    max = a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data>max)
          max=a->data;
    }
    return max;            
}

 //Function to find minimum of the data from slist
 int findMin(SLIST *t)
 {
    NODE *a;
    a=t->st;
    int min;
    min=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data<min)
          min=a->data;
    }
    return min;
 } 

 //Function to delete 1st node from slist
void delFirst(SLIST *t)
{
    NODE *a;
    a=t->st;
    if(a==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    t->st=a->next;
    free(a); //jo apan node delete kela tyani ji adhi memory hold keli hoti te memory apan release keli free(a) use karun
    t->cnt = t->cnt-1;
    return;
}

//Function to delete last NODE from slist
void delLast(SLIST *t)
{
    NODE *a,*b;
    a=t->st;
    if(a==NULL) //List is empty
    {
        printf("\nEmpty list");
        return;
    }
    if(a->next==NULL) //List contains only 1 node i.e. list contains only 1st node
       t->st=NULL;
    else
    {
        while(a->next!=NULL)
        {
            b=a;
            a=a->next;
        }
        b->next=NULL; //last node chya adhichya node chya next part chi value null mhnun set keli
    }   
    free(a);
    t->cnt = t->cnt - 1;
}

//Function to delete all NODES from list
/*void delAll(SLIST *t)
{
    while(t->st!=NULL)
      delFirst(t);
}*/

//OR; Function to delete all the nodes written below is more efficient than the function written above bcz in above function their is call to function and call to function is more costly
void delAll(SLIST *t)
{
    NODE *a,*b;
    a=t->st;
    while(a!=NULL)
    {
        b=a;
        a=a->next;
        free(b);
    }
    t->st=a;
    t->cnt=0;
}

//Function to display list data in reverse order
void revDisplay(NODE *a)
{
    if(a==NULL)
      return; // Return zalyavr control function chya tya part madhe jaeil jithun control kayam top la jat hota i.e. control will go to printf statement and the data will be printed in reverse order
    revDisplay(a->next); //Call to function 
    printf("%4d",a->data);
}  //Call from main revDisplay(p.st); adhichya saglya functions madhe apan address of p pass karat hoto bcz tya funtions madhe sagle slist type che variable hote pan ethe ek variable node type cha pan ahe 

//Function to reverse the list i.e. reverse the order of the nodes to make 1st node as last node and last node as 1st node and jevha apan display function la call kru tevha sagla data reverse order madhe display hoil; ethe khr madhe nodes chi position change keliye and vr phkt apan reverse order madhe print kel hot
void revList(SLIST *t)
{
    NODE *a,*b,*c;
    a=NULL;
    b = t->st;
    while(b!=NULL)
    {
        c=b->next;
        b->next=a;
        a=b;
        b=c;
    }
    t->st=a;
}// Call from main : revList(&p);

//Function to count odd data nodes
int oddDataCnt(SLIST *t)
{
    NODE *a;
    a=t->st;
    int cnt=0;
    while(a!=NULL)
    {
       if(a->data%2==1)
        cnt++;
       a=a->next;  
    }
    return cnt;
}
//function to count even data nodes 
int evenDataCnt(SLIST *t)
{
    NODE *a;
    a=t->st;
    int cnt =0;
    while(a!=NULL)
    {
        if(a->data%2==0)
          cnt++;
        a=a->next;  
    }
    return cnt;
}
//function to display odd position node data
void oddPosData(SLIST *t)
{
    NODE *a;
    a=t->st;
    int i=1;
    while(a!=NULL)
    {
        if(i%2==1)
          printf("\nOdd position data : %d",a->data);
        a=a->next;
        i++;  
    }
} 
//Function to display even position node data 
void evenPosData(SLIST *t)
{
    NODE *a;
    a=t->st;
    int i=1;
    while(a!=NULL)
    {
        if(i%2==0)
          printf("\nEven position data : %d",a->data);
        a=a->next;
        i++;   
    }
}

//Function to do sum of two successive nodes data as 3rd node data
void insertSumEnd(SLIST *t)
{
    NODE *a,*b,*c;
    a=t->st;
    int val;
    while(a!=NULL)
    {
      b = a->next;
      if(b==NULL)
        break;
      val = a->data + b->data;
      c= createNode(val);
      c->next=b->next;
      b->next=c;
      a=c->next;
      t->cnt++;  
    }
}

//Function to do sum of 2 nodes and insert the sum node at the begin of 2 nodes
void insertSumBegin(SLIST *t)
{
    int val;
    NODE *a,*b,*c,*tmp;
    a=t->st;
    while(a!=NULL)
    {
        b = a->next;
        if(b==NULL)
          break;
        val = a->data + b->data;
        c = createNode(val);
        c->next=a;
        if(a==t->st)//mhnje jr 1st node asel tr c la apan 1st node declare kel
          t->st=c;
        else
          tmp->next=c;
        a = b->next;
        tmp = b;
        t->cnt++;      
    }
} 

//Function to delete ith position node from the list
void deliNode(SLIST *t,int pos)
{
    NODE *a,*b,*c;
    a = t->st;
    int i=1;
    if(pos<1 || pos>t->cnt)
      return;
    if(pos==1) //If we want to delete 1st node
      delFirst(t);
    else
      {
        if(pos==p->cnt) //If we want to delete last node
          delLast(t);
        else
        {
            while(i<pos)
            {
                b = a;
                a = a->next;
                i++;
            }
            c = a->next;
            b->next = c;
            free(a);
            p->cnt--;
        }  
      }    
}

//Function to insert new node before ith position node
void insertBefore(SLIST *t,int pos,int d)
{
    NODE *a,*b,*c;
    a = t->cnt;
    int i=1;
    if(pos<1 || pos>t->cnt)
      return;
    if(pos==1)
      addBeg(t,d);
    else
    {
        while(i<pos)
        {
            b=a;
            a=a->next;
            i++;
        }
        c = createNode(d);
        b->next=c;
        c->next=a;
        p->cnt++;
    }    
}

//Function to insert node after ith position
void insertAfter(SLIST *t,int pos,int d)
{
    NODE *a,*b,*c;
    a = t->st;
    int i=1;
    if(pos<1 || pos>t->cnt)
      return;
    if(pos==p->cnt)
      addEnd(t,d);
    else
    {
        while(i<=pos)
        {
            b = a;
            a = a->next;
            i++;
        }
    }
}

//func to search a value from the specified SLIST  
//  if found return address i.e. NODE * is returning address
NODE *search(SLIST *p,int val)
{
    NODE *a=p->st;
    while (a!=NULL)
    {
        if(a->data==val)
            break;
        a=a->next;           
    }
    return a;
}

// func to implement find and replace 
void findRepl(SLIST *p,int sv,int rv)
{
    NODE *a=p->st;
    while (a!=NULL)
    {
        if(a->data==sv)
        a->data=rv;
        a=a->next;
    }   
}

// copying one LL to another by calling addEnd func
SLIST copyList(SLIST *t)
{
    SLIST b;
    NODE *a=b->st;
    init(&b);
    while (a!=NULL)
    {
        addEnd(&b,a->data);
        a->next;
    }
    return a;
}

// copying one LL to another by calling addBeg func in reverse order
SLIST reverseCopy(SLIST *t)
{
    SLIST b;
    NODE *a=b->st;
    init(&b);
    while (a!=NULL)
    {
        addBeg(&b,a->data);
        a->next;
    }
    return a;
}