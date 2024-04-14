#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[10];
    int i=0,nc=0,pc=0,zc=0;
    system("cls");
    printf("Array Data");
    for(i=0;i<10;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]>0)
        pc++;
        else
       { if(x[i]<0)
        nc++;
        else
        zc++;
       }
    }
    printf("\npositive %d \nnegative %d \nzeros %d",pc,nc,zc);
}