#include<stdio.h>
#include<stdlib.h>
int main()
{
    int no,tot=0;
    printf("\nEnter no:");
    scanf("%d",&no);
    while(no>0)
    {
        tot=tot*10+(no%10);
        no/=10;
    }
    printf("\nReverseNo:%d",tot);
    return 0;
}