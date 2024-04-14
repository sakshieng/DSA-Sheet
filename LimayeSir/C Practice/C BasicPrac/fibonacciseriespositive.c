#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,i;
    int n;
    scanf("%d",&n);
    system("cls");
    printf("\nenter no");
    for(i=1,a=-1,b=1;i<=n;++i) //here in for loop ++i and i++ are same
    {
        c=a+b;
        printf("%5d",c);
        a=b;
        b=c;
    }
    return 0;
}