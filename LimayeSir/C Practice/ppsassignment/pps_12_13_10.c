// 10) Write a program in C to reverse a string using recursion.
#include <stdio.h>
#include <stdlib.h>
char *reverse(char *str);
void main()
{
    int i, j, k;
    char str[100];
    system("cls");
    char *rev;
    printf("Enter the string:\t");
    scanf("%s", str);
    printf("The original string is: %s\n", str);
    rev = reverse(str);
    printf("The reversed string is: %s\n", rev);
    getch();
}
char *reverse(char *str)
{
    static int i = 0;
    static char rev[100];
    if (*str)
    {
        reverse(str + 1);
        rev[i++] = *str;
    }
    return rev;
}