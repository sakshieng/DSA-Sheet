#include<stdio.h>
int main()
{
    int x[10];
    int i=0;
    system("cls");
    while(i<10)
    {
        printf("element%d:",i);
        scanf("%d",&x[i]);
        i++;
    }
    for(i=0;i<10;i++)
    printf("%d\t",x[i]);
}