#include<stdio.h>
void main()
{
    void fact();
    fact();
    return ;
}
void fact()
{
    int no;
    long int factor=1;
    printf("\nEnter No:");
    scanf("%d",&no);
    while(no>0)
    {
        factor=factor*(no--);
    }
    printf("Factorial:%d",factor);
    return ;
}