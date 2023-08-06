#include<stdio.h>
#include<stdlib.h>
void main()
{
   int fact(int);
   int no;
   int res;
   printf("\nEnter no");
   scanf("%d",&no);
   res=fact(no);
   printf("factorials:\n",res);
   return;
}
int fact(int a)
{
    if(a==0)
    return 1;
    else
    return(a*fact(a-1));
}