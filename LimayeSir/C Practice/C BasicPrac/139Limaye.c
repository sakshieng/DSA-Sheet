#include<stdio.h>
int main()
{
    int x[10],i=0;
    while(i<10)
    {
        printf("\nData:");
        scanf("%d",&x[i]);
        if(i && x[i] < x[i-1])
        continue;
        i++;
    }
    printf("\nData\n");
    for(i=0;i<10;i++)
    printf("%4d",&x[i]);
}