#include<stdio.h>
int main()
{
    char a;
    printf("\nenter a character");
    scanf("%c",&a);
    printf("\n %c is %s a character ",a,((a>='0' && a<='9')?"digit":"other"));
    return 0;
    //%s is very imp to mention
}
