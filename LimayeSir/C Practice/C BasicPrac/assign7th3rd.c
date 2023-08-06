#include<stdio.h>
int main()
//a=certain age
{
    int a;
    printf("\nEnter a certain age");
    scanf("%d",&a);
    if(a>=0 && a<18)
    printf("\nNot Eligible");
    else
    {
        if(a>=18 && a<=58)
        printf("\nEligible");
        else
        printf("\nNot Eligible");
    }
    return 0;

}