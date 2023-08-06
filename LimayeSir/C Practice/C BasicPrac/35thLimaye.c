#include <stdio.h>
int main() 
{
    char ch;
    printf("\nEnter a character");
    scanf("%c",&ch);
    if(ch=='0' || ch=='1')
    printf("\nBinary");
    else
    printf("\nNot binary");
    printf(" Character");
    return 0;
}