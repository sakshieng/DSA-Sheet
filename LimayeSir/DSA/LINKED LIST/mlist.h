#include<stdio.h>
#include<stdlib.h>
#include "slist.h"
//Code by Sakshi:
// program for manipulation multiple linked list
void createList(SLIST *p)
{
   NODE *a=p->st,*b;
   int d;
   if(p->st != NULL)
      delAll(p);
   while(1)
   {
      printf("\nData:");
      scanf("%d",&d);
      if(d==0)
         break;
      a=createNode(d);
      if(p->st==NULL)         
         p->st=a;
      {
         b=getLastNode(p->st);
         b->next=a;
      }
      b=a;
      p->cnt++;
   }      
}

// as here copy by value hence SLIST p not *p
// func to merge 2 ordered list
SLIST merge(SLIST *p,SLIST *q)
{
   int data;
   NODE *a=p->st;
   NODE *b=q->st;
   NODE *c,*d;
   // a and b are poniters a->data not a.data
   SLIST r;
   sort(p);
   sort(q);
   init(&r);
   while(a && b)
   {
      if(a->data < b->data)
      {
         data=a->data;
         a=a->next;
      }
      else
      {
         data=b->data;
         b=b->next;
      }
      // d destination mdhla last node
      c=createNode(data);
      if(r.st == NULL)
         r.st=c;
      else
         d->next=c;
         d=c;       
         r.cnt++;  
   }
   // as when a or b null astil vrchya loop mdhe janarch nhi so again we have to check for destination list empty list
   while (a)
   {
      data=a->data;
      c=createNode(data);
      if(r.st==NULL)
         r.st=c;
      else
         d->next=c;
         d=c;
         r.cnt++;
         a=a->next;         
   }
   while (b)
   {
      data=b->data;
      c=createNode(data);
      if(r.st==NULL)
         r.st=c;
      else
         d->next=c;
         d=c;
         r.cnt++;
         b=b->next;   
   }
   
   return r;  
}

// intersection of 2 lists
// returning type slist
SLIST intersectionList(SLIST *p,SLIST *q)
{
   NODE *a,*b,*c,*d;
   int data;
   SLIST r;
   init(&r);
   sort(p);
   sort(q);
   if(p->st==NULL || q->st==NULL)
      return r;
   a=p->st;
   b=p->st;
   while (a && b)
   {
      if(a->data < b->data)
      {
        a=a->next;
        continue;
      }
      else
      {
         // d destination mdhil r cha last pointer
         if(b->data < a->data)
         {
            b=b->next;
            continue;
         }
      }
      data=a->data;
      a=a->next;
      b=b->next;
      if(r.st==NULL)
         r.st=c=createNode(data);
      else
      {
         if(d->data == data)
            continue;
         c=createNode(data);
         d->next=c;            
      }         
      d=c;
      r.cnt++;
   }
   return r;
}
// union and merge mdhe union mdhe no repeat of nodes
// func of union of 2 lists
SLIST unionList(SLIST *p,SLIST *q)
{
   SLIST r=merge(p,q);
   int flg=0;
   NODE *a=r.st,*b,*c;
   while (a!=NULL)
   {
      b=a->next;
      flg=0;
      while (a->data==b->data && a!=NULL && b!=NULL)
      {
         c=b;
         flg=1;
         b=b->next;
         free(c);
         r.cnt--;         
      }
      if (flg==1)
         a->next=b;
      a=b;         
   }
   return r;
}
// here repeated values get cancelled by flg declaration means if 2  2  4  5  6  6  6  7  8  9  9  13 18
// for this list from first 2 it will jump to 4 from first 6 it will jump to 7 directly