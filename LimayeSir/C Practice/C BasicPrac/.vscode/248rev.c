//reverse using static variable
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int no,res;
    int rev(int);
    printf("\nEnter no");
    scanf("%d",&no);
    res=rev(no);
    printf("\nReverse no");
    return;
}
int rev(int a)
{
    static int r=0;
    int rem;
    if(a==0)
    return r;
    else
    {
        rem  = a%10;
        r=r*10+rem;
        return(rev(a/10));
    }
}