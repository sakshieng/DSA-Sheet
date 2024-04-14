//write a func to check inputed array is of ordered data or not
#include<stdio.h>
void main()
{
    void isordered();
    isordered();
    return;
}
void isordered()
{
    int i=0,x[10];
    printf("\nArray Data\n");
    for(i=0 ; i<10 ;i++)
    scanf("%d",&x[i]);
    for(i=0 ; i<10 ;i++)
    {
        if(x[i] < x[i-1])
        break;
    }
    if(i == 10)//imp
    printf("\nOrdered");
    else
    printf("\nUnordered");
    return;
}