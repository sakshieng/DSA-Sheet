#include <stdio.h>
int main() 
{
    int i,j,n;
    printf("\nEnterLineNo\n");
    scanf("%d",&n);
    printf("Pattern\n");
    for(i=n;i>=0;i--)
    {
        for(j=1;(i+j<=n+1);j++)
        printf("*");
        printf("\n");
    }
    return 0;
}