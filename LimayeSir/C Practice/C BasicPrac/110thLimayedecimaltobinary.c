#include <stdio.h>
int main() 
{
    int no,rem;
    long int fact=1,bno=0;
    /*fact is divisible factor which takes value 1,10,100,1000...
    bno is binary no*/
    printf("\nEnter Number");
    scanf("%d",&no);
    while(no>0)
    {
        rem=no%2;
        bno=bno+(fact*rem);
        fact*=10;
        no/=2;
    }
    printf("\nBinary No:%ld",bno);
    return 0;
}