#include<stdio.h>
#include<stdlib.h>
#include "slist.h"
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
// func to delete i^th position from the list
void deliNode(SLIST *p,int pos)
{
   NODE *a=p->st,*b,*c;
   int i=1;
   if(pos>p->cnt || pos<1)
   return;//case of empty list
   if(pos==1)
   delFirst(p);
   else
   {
    if(pos==p->cnt)
    delLast(p);
    else
    while (i<pos)
    {
        b=a;
        a=a->next;
        i++;
    }
    c=a->next;
    b->next=c;
    free(a);
    p->cnt--;//jri p->cnt=0 asel tri chalte as delfirst mdhe te pahile jail
   }
}
/*
i   a   b   c

*/