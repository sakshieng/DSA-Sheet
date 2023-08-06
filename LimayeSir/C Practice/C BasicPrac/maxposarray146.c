#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,xpos=0,x[10];
    system("cls");
    for(;i<10;i++)
    {
        printf("\nEnter No:");
        scanf("%d",&x[i]);
    }
    for(i=0;i<10;i++)
    {
        if(x[i]>x[xpos])
        xpos=i;
    }
    printf("\nData:\n");
    for(i=0;i<10;i++)
    printf()
}