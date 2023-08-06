#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[10],i,cnt,sv;
    system("cls");
    printf("\nArray\n");
    for(i=0;i<10;i++)
    scanf("%d",&x[i]);
    printf("\nSearch Value");
    scanf("%d",&sv);
    for(i=cnt=0;i<10;i++)
    {
        if(x[i]==sv)
        cnt++;
    }
    printf("%d occured %d times",sv,cnt);
}