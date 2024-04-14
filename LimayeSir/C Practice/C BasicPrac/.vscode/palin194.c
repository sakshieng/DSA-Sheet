#include<stdio.h>
#include<stdlib.h>
void main()
{
   void palindrome();
   palindrome();
   return ;
}
void palindrome()
{
    int tmp=0,no,tot=0;
    printf("\nEnter No");
    scanf("%d",&no);
    while(no>0)
    {
        tot=tot*10+(no%10);
        no/=10;
    }
    if(tmp == tot)
    printf("\nPalindrome");
    else
    printf("\nNon Palindrome");
    return;
}