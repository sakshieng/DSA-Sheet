#include<stdio.h>
#include<stdlib.h>
#include "mlist.h"
//Code by Sakshi:

int main()
{
   int opt;
   SLIST p,q,r;
   init(&p);
   init(&q);
   init(&r);
   NODE *a,*b,*c,*d;
   while (1)
   {
    printf("\nMenu\n1.Create list p\n2.Create list q\n3.Merge\n4.Display list p\n5.Display list q\n6.Display list r\n7.\n8.Union of 2 lists\nOption: ");
    scanf("%d",&opt);
    if(opt>6)
        break;
    switch(opt)
    {
        case 1:
            createList(&p);
            break;
        case 2:
            createList(&q);    
           break;
        case 3:
            r=merge(&p,&q);
            break;
        case 4:
            display(&p);
            break;       
        case 5:
            display(&q);
            break;       
        case 6:
            display(&r);
            break;       
        case 7:

        case 8:
            r=unionList(&p,&q);
            break;
    }
   }
   return 0;
}