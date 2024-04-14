#include<stdio.h>
int main()
{
    int x[10],i=0;
    void display(int [],int);
    printf("\nData array:");
    for(i=0;i<10;i++)
 scanf("%d",&x[i]);
 display(x,10);
 return 0;
}
void display(int y[],int n)
{
    int i=0;
    printf("\nArray data");
    while(i<n)
    {
        printf("%4d",y[i]);
        i++;
    }
    return;
}