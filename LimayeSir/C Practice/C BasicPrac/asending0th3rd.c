#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[10];//array declaration
    int pos,i,tmp,j;
    system("cls");
    for(i=0;i<10;i++)
    {
        scanf("%d",&x[i]);//input array elements
    }
    printf("\nArray Data:\n");
    for(i=0;i<10;i++)
    printf("%4d",x[i]);//print array
    for(i=0;i<9;i+=3)
    {
        pos=i;
        for(j=i+3;j<10;j+=3)//as for 0th 3rd hence take j=i+3
        {
            if(x[j]<x[pos])
            pos=j;
        }
        if(i!=pos)//
        {
            tmp=x[i];
            x[i]=x[pos];
            x[pos]=tmp;
        }
        
    }
    printf("\nArray After Sorting:\n");
        for(i=0;i<10;i++)
        printf("%4d",x[i]);
}