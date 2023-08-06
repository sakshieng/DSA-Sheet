#include<stdio.h>
int main()
{
    int no,i;
    printf("\nenterno:");
    scanf("%d",&no);
    printf("\ntable of no");
    for(i=1;i<=10;i++)
    printf("%5d",no*i);
    return 0;
}