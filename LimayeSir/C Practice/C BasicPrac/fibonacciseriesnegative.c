#include<stdio.h>
int main()
{
    int a,b,c,i;
    printf("\nenter no");
    for(i=1,a=-1,b=-1;i<=10;i++)
    {
        c=a+b;
        printf("%5d",c);
        a=b;
        b=c;
    }
    return 0;
}