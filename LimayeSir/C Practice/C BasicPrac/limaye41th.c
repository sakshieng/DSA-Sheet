#include<stdio.h>
int main()
{   char ch;
    printf("\nEnter character:");
    scanf("%c",&ch);
    if (ch>='A'&& ch<='Z')
        printf("\nUpper case alphabet character.");
    else if (ch>='a'&& ch<='z')
        printf("\nLower case alphabet character.");
    else {if (ch>='0'&& ch<='9')
        printf("\nDigit character.");
    else 
        printf("\nSpecial character.");}
         
    return 0;
}
