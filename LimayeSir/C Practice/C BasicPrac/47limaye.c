#include <stdio.h>
int main()
//it will only compute sum of first 5 numbers
{
    int i=1,tot=0,x;
    while(i<=5)
    {
        printf("\nEnter No:");
        scanf("%d",&x);
        tot=tot+x;
        i++;

    }
    printf("\nsum:%d",tot);
    return 0;
}