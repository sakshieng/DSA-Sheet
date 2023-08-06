#include<stdio.h>
//1+11+111+1111+.....
int main()
{
    int i,j=1,n,sum=0; //we declared j directly as 1 only one for loop is used
    printf("Enter number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d+",j);//imp step
        sum+=j;
        j=(j*10)+1;//this is for displaying sum
    }
    printf("\nSum: %d",sum);
}