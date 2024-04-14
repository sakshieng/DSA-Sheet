#include<stdio.h>
#include<stdlib.h>
void main()
{
    void rev();
    rev();
    return ;
}
void rev()
{
    int no,tot=0;
    printf("\nEnter No:");
    scanf("%d",&no);
    while(no>0)
    {
        tot=tot*10+(no%10);
        no/=10;
    }
    printf("Reverse No:%d",tot);
    return;
}