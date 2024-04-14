//find total and average of elements of array of size 10
#include<stdio.h>
void main()
{
    void findtotavg();
    findtotavg();
    return;
}
void findtotavg()
{
    int i=0,tot=0,x[10];
    printf("\nArray Data\n");
    for(i=0 ; i<10 ; i++)
    {
        scanf("%d",&x[i]);
        tot += x[i];
    }
    printf("\nArray Data\n");
    for(i=0 ; i<10 ; i++)
    printf("%4d",x[i]);
    printf("\nTotal:%d \nAvg:%d",tot,tot/10);
    return;
}