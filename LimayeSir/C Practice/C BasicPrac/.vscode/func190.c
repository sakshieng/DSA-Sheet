//tables 
#include<stdio.h>
void main()
{
    void table();
    table();
    return;
}
void table()
{
    int i=1,n;
    printf("\nNumber ");
    scanf("%d",&n);
    printf("\nTable\n");
    while(i<=10)
    {
        printf("%4d",n*i);
        i++;
    }
    return;
}