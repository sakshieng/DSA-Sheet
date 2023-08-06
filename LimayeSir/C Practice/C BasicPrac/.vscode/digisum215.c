#include<stdio.h>
#include<stdlib.h>
int main()
{
   int digisum();
   printf("\nDigit sum:%d",digitsum());
   return 0;
}
int digitsum()
{
    int no,tot=0;
    printf("\nEnter no");
    scanf("%d",&no);
    while(no>0)
    {
        tot+=(no%10);
        no/=10;
    }
    return tot;
}