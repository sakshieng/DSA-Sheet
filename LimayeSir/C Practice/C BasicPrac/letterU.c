#include<stdio.h>
int main()
{
    int i=1,j=1,n;
    printf("\nPattern\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
    {
            if(j==1||i==n||j==n)
            printf("*");
            else
            printf(" ");
            

   }
        printf("\n");
  }
    
    return 0;
}