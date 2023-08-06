#include<stdio.h>
int main()
{
    int no,i,cube;
    printf("Enter a number: ");
    scanf("%d ",&no);
    for(i=1;i<=no;i++)
    {
       printf("\nCube of %d is %d",i,(i*i*i));
    }
}