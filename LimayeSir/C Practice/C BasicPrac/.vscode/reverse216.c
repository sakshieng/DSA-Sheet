#include<stdio.h>
#include<stdlib.h>
int main()
{
   int reverse();
   printf("\nReverse of no %d",reverse());  
   return 0;
}
int reverse()
{
    int no,rev=0;
    printf("\nEnter no");
    scanf("%d",&no);
    {
        rev=rev*10+no%10;
        no/=10;
    }
    return rev;
}