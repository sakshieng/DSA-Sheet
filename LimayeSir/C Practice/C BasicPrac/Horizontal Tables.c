#include <stdio.h>
void main()
{
    int i,j;
    printf("\nTable\n");
    for(i=1;i<=10;i++)
    {
        for(j=2;j<=10;j++)
        printf("%5d",i*j);
        printf("\t");
    }
    return;
}