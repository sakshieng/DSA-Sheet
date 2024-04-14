#include <stdio.h>
int main()
{
    int no,ldig;
    printf("Enter Number");
    scanf("%d",&no);
    while(no>0)
    {
        ldig=no%10;
        no/=10;
    }
    printf("\nldig:%d",ldig);
    return 0;
}