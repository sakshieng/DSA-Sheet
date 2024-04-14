//without using global variable
#include<stdio.h>
int res=0;
int rev(int a)
{
    int rem;
    if(a==0)
    return res;
    else
    {
        rem=a% 10;
        res= res*10+ rem;
        return(rev(a/10));
    }
    printf("\nReverse no :%d",res);
}
