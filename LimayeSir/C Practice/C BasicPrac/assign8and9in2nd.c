#include<stdio.h>
int main()
{
    int i,no,sum=0;
    printf("Enter a number: ");
    scanf("%d",&no);
    for(i=1;i<=no;i++)
    {
        sum+=i;
        printf("%d ",i);
    }
    printf("\nsum= %d",sum);
    return 0;
}