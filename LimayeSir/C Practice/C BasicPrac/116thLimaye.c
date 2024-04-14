#include <stdio.h>
int main()
{
    int no,ldig,rdig;
    printf("Enter Number");
    scanf("%d",&no);
    ldig=rdig=no%10;
    while(no>0)
    {
        ldig=no%10;
        no/=10;
    }
    printf("\nldig:%d \nrdig:%d",ldig,rdig);
    return 0;
}