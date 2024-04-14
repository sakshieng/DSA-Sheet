#include<stdio.h>
void main()
{
    int power(int,int);
    int no,pow;
    int res;
    printf("\nEnter no");
    scanf("%d",&no);
    res=sum(no);
    printf("\nValue :%d",res);
    return;
}
int sum(int a)
{
    if(a==0)
    return 0;
    else
    return(a%10+sum(a/10));
}