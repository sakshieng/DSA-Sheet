#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
union pqr
{
    int a;
    char b;
    float c;
};
void main()
{
    union pqr p;
    p.a=10;
    printf("\n%d",p.a);
    p.b='A';
    printf("\n%c",p.b);
    p.c=9.2;
    printf("\n%f",p.c);
    return;
}