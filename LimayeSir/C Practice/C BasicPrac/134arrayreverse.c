#include<stdio.h>
#include<stdlib.h>
int main()
{ int x[10],i,j,tmp;
system("cls");
printf("\nArray:\n");
scanf("%d",&x[i]);
printf("\nBefore Processing\n");
for(i=0;i<10;i++)
printf("%4d",x[i]);
for(i=0,j=9;i<j;i++,j--)
{
    tmp=x[i];
    x[i]=x[j];
    x[j]=tmp;
}
printf("\nAfter processing:\n");
for(i=0;i<10;i++)
printf("%4d",x[i]);
return 0;
}