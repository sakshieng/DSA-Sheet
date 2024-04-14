#include<stdio.h>
int main()
{
    int ary[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printf("%d",*(*(ary+1)+1));
}