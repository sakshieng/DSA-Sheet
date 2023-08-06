#include<stdio.h>
void main()
{
    int fibo(int);
    int no;
    int res;
    printf("\nEnter no");
    scanf("%d",&no);
    res=fibo(no);
    printf("\nValue :%d",res);
    return;
}
int fibo(int a,int b,int c)
{
    if(a==0)
    return 0;
    else
    return(b+c);
}