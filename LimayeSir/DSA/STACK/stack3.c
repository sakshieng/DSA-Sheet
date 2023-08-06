#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
//Code by Sakshi:

int main()
{
   int opt,d;
   STK s;
   init(&s);
   while (1)
   {
      printf("\nStack menu\n1.Push\n2.Pop\n3.Stack top\n4.Display\n5.Exit\nOption: ");
      scanf("%d",&opt);
      if(opt > 4)
         break;
      switch(opt)         
      {
         case 1:
            printf("\nData:");
            scanf("%d",&d);
            push(&s,d);
            break;
         case 2:
            pop(&s);
            break;
         case 3:
            stackTop(&s);
            break;
         case 4:
            display(&s);
            break;               
      }
   }
   return 0;
}