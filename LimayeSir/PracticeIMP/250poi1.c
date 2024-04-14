#include<stdio.h>
void main()
{
    int x=10;
    printf("\nx:%d",x);
    printf("\naddress:%u",&x);
    printf("\nValue:%d",*(&x));
    return;
}