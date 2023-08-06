#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("Even Natural No");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d ",2*i);
        sum=sum+(2*i);
    }
    printf("\nSum:%d",sum);
}