#include<stdio.h>
int main()
{
    int x[5];
    int i=0;
    system("cls");
    printf("Array Data:");
    while(i<5)
    {
        printf("\nx[%d]:",i);
        scanf("%d",&x[i]);
        i++;
    }
    printf("\nData:\n");
    for(i=0;i<5;i++)
    printf("%5d",x[i]);
}