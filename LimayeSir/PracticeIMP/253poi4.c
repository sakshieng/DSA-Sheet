#include<stdio.h>
void main()
{
    int a=10;
    int *b;
    int *(*c);
    b=&a; c=&b;
    printf("\n%d",a);
    printf("\n%u",*(&a));
    printf("\n%d",*(&a));
    printf("\n%d",*b);
}