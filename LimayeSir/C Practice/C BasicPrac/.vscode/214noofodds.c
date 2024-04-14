#include<stdio.h>
#include<stdlib.h>
int main()
{
   int oddeven();
   int i=1,cnt=0;
   while(i<5)
   {
       cnt+=oddeven();
       i++;
   }
   printf("\nOdd nos %d",cnt);
   printf("\nEven nos %d",5-cnt);
   return 0;
}
int oddeven()
{
    int no;
    printf("\nEnter no");
    scanf("%d",&no);
    return(no % 2);
}