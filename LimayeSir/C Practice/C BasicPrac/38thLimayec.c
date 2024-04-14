#include <stdio.h>
int main() 
{
    int a;
    printf("\nEnter a number");
    scanf("%d",&a);
    if(a<0)
    printf("\n Below 0");
    else
    {
        if(a>100)
        printf("\n Above 100");
        else
        printf("\n Within 0-100");
    }
    return 0;
}