#include<stdio.h>
void main()
{
    char a='p';
    char *b;
    b=&a;
    printf("\n%c",a);
    printf("\n%c",*(&a));
    printf("\n%u",&b);
    printf("\n%u",*(&b));
    printf("\n%u",*b);
    *b=*b+32;
    printf("\n%c",*b);
}