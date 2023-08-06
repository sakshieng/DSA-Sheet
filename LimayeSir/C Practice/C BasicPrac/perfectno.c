#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter number");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
        if(n==sum)       
         printf("Perfect No.");
        else
        printf("Not perfect no.");
    

    return 0;
}