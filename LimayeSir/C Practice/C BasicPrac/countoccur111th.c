#include<stdio.h>
int main()
{
    int dig,factor=1,dno=0;
    long int no;
    printf("\nEnter binary no");
    scanf("%ld",&no);
    while(no>0)
    {
        dig=no%10;
        if(dig>1)
        break;
        dno=dno+(factor*dig);
        factor*=2;
        no/=10;
    }
    if(no>0)
    printf("\nInvalid Input");
    else
    printf("\nDecimal No.:%d",dno);
    return 0;
    //dno=decimal number if we input a binary no it will give equivalent decimal no 
    //other than binary loop gets break and output will be invalid input
}