#include<stdio.h>
int main()
{
    int ary[2][2][3]={{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    int *p;
    p=ary;
    printf("%d%d",*p,*p+10);

}