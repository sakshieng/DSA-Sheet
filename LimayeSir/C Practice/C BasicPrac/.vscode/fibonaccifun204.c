#include<stdio.h>
void main()
{
    void fibonacci();
    fibonacci();
    return;
}
void fibonacci()
{
    int a,b,c;
    for(int i=1,a=-1,b=1;i<=10;i++)
    {
        c=a+b;
        printf("%4d",c);
        a = b;
        b = c;
    }
    return;
}