#include<stdio.h>
//1+11+111+1111+.....
int main()
{
    int i,j=1,n,sum=0; 
    printf("Enter number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d",j);//imp step
        sum+=j;
        j=(j*10)+1;//this is for displaying sum
if(i==n){
break;
}
printf("+");
    }
    printf("\nSum: %d",sum);
}-