#include <stdio.h>
int main() 
{
    int i,j,n;
    printf("\nEnterLineNo.");
    scanf("%d",&n);
    printf("Pattern\n");
    n=(n%2==0)?n+1:n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j||i==n||j==1)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}