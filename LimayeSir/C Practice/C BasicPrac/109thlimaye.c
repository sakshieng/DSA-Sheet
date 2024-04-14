#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int no,dig,i,tot=0;
    printf("\nenter 5 digit number");
    scanf("%d",&no);
    for(i=1;i<=5;i++)
    {
        dig=no%10;
        tot+=dig;
        no/=10;
    }
    printf("\nSum :%d",tot);
    return 0;
}