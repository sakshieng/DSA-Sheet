#include <stdio.h>
int main() 
{
    int i=1,j=1,n;
    printf("\nline count");
    scanf("%d",&n);
    printf("\npattern\n");
    for(i=1;i<=n;i++)
    {
        j=1;
        while(j<=n)
        {
            if(i==1||i==n||j==1||j==n)
            printf("*");
            else
            printf(" ");
            j++;
        }
        printf("\n");
    }
    return 0;
}