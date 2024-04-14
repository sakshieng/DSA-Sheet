//func to find min max element from an array
#include<stdio.h>

#include<stdlib.h>
void main()
{
    void maxmin();
    maxmin();
    return;
}
void maxmin()
{
    int i=0,max,min;
    system("cls");
    int x[10];
    for(i=0; i<10 ; i++)
    {
        printf("\nEnter No:");
        scanf("%d",&x[i]);
        if(i==0)
        {
        max=x[i];
        min=x[i];
        }
        else
        {
        if(x[i]>max)
         max=x[i];
        else
        if(x[i]<min)
         min=x[i];
        }
    }
    printf("\nData\n");
    for(i=0 ; i<10 ;i++)
    printf("%5d",x[i]);
    printf("%d%d\n\n",max,min);
}