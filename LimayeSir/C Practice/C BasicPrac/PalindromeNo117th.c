#include <stdio.h>
int main()
{
    int no,tmp=0,rev=0;
    // its very imp to initialize tmp=0 and rev=0
    printf("\nEnter Number");
    scanf("%d",&no);
    for(no=tmp;(no>0);no/=10)
{
      rev=rev*10+(no%10);
}
    if(tmp==rev)
    printf("\nPalindrome");
    else
    printf("\nNot Palindrome");
    return 0;
}