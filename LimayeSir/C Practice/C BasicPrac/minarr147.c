#include<stdio.h>
#include<stdlib.h>
int main()
{
   int i=0,npos=0,x[10];
   system("cls");
   for(; i<10 ;i++)
   {
       printf("Enter no:\t");
       scanf("%d",&x[i]);
       if(i && x[i]<x[npos])
       npos=i;
   }
   for(i=0 ; i<10 ; i++)
   printf("%4d",x[i]);
   printf("\nMin Position:%d\n Value:%d",npos,x[npos]);
   return 0;
}