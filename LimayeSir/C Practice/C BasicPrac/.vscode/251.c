#include<stdio.h>
void main()
{
    int x=10;int *y;
    y=&x;
    printf("\n%d",x);
    printf("\n%u",&x);
    printf("\n%d",*(&x));
    printf("\n%u",&y);
    printf("\n%u",y);
    printf("\n%u",*(&y));
    printf("\n%u",*(*(&y)));
    *y=*y+5;
    printf("\n%d",x);
}