#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[5];
    int i=0,tot=0;
    system("cls");
    printf("Array Data:");
    while(i<5)
    {
        printf("\nx[%d]:",i);
        scanf("%d",&x[i]);
        tot=tot+x[i];
        i++;
    }
    printf("\nArray:\n");
    for(i=0;i<5;i++)
    printf("%4d",x[i]);
    printf("\nTotal:%d",tot);
    
}