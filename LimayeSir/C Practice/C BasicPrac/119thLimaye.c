#include <stdio.h>
int main() 
{
    int i;
    printf("\nASCII Characters\n");
    i=0;
    while(i<=255)
    {
        printf("%c-%d",i,i);
        if(i%9==0)
        printf("\n");
        printf("\t");
        i++;
    }
    return 0;
}