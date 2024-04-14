#include<stdio.h>
int main()
{
    char ch;
    printf("Enter a character\n");
    scanf("%c",&ch);
    //inputed char is alphabet,digit or special char using if..else
    printf("\n %c is %s character",ch,((ch>='A' && ch<='Z')?"Alphabet":
    ((ch>='0' && ch<='9')?"Digit":"Special")));
    return 0;       
}