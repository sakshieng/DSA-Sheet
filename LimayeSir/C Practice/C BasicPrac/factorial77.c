#include<stdio.h>
#include<stdlib.h>
int main()
{
    int no;
    long int fact=1;
    system("cls");
    scanf("%d",&no);
    for(;(no>1);no--)
    fact*=no;
    printf("\nFactorials:%ld",fact);
    return 0;
}