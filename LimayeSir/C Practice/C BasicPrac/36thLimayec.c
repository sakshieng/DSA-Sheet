#include <stdio.h>
int main() 
{
    int a;
    printf("\nEnter a number");
    scanf("%d",&a);
    if(a>=0 && a<=100)
    printf("\nWithin the range");
    else
    printf("\nOut of range");

    return 0;
}