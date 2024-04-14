#include<stdio.h>
//Floyd's Triangle
int main()
{
    int i,j,n;
    printf("\nPattern");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d\t",(i+j)%2);
        }
         printf("\n"); 
    }
}