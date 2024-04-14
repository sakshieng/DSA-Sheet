#include <stdio.h>
int main() 
{
    int a;
    printf("\nEnter a number");
    scanf("%d",&a);
    if(a>0)
    printf("\n +ve");
    else
    {
        if(a<0)
        printf("\n -ve");
        else
        printf("\n Zero");
    }

    return 0;
}