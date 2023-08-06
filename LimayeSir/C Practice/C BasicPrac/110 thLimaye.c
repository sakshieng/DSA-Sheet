#include<stdio.h>
int main()
{
    long int no;
    printf("\nEnter No.");
    scanf("%ld",&no);
    while(no>0)
    {
        if(no%10>1)
        break;
        no/=10;
    }
    if(no==0)
    printf("\nBinary");
    else
    printf("\nNot Binary");
    return 0;
}