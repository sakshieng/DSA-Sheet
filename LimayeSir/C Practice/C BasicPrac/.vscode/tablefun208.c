#include<stdio.h>
void main()
{
    void table();
    table();
    return;
}
void table()
{
    int i=1,j=1;
    printf("\nTables from 1 to 10\n");
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=10; j++)
        printf("%4d",i*j);
        printf("\n");
    }
    return;
}