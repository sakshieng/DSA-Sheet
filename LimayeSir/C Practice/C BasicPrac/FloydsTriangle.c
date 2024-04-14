#include<stdio.h>
//Floyd's Triangle
//when we take j=0 then for n=5 5 lines output came but for j=1 for n=5 4 lines output came
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