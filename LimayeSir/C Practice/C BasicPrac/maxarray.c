#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,x[10],max;
    system("cls");
    for(;i<10;i++)
    {
        printf("\nEnter No.");
        scanf("%d",&x[i]);
        if(i==0)
        max=x[i];
        else
        {
            if(x[i]>max)
            max=x[i];
        }
    }
    printf("\nData:\n");
    for(;i<10;i++)
    printf("%5d",x[i]);
    printf("%d",max);
}