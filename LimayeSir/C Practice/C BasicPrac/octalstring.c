#include <stdio.h>
#include <stdlib.h>
#define N 50
int main()
{
    char p[N];
    system("cls");
    int i = 0;
    printf("\nString:");
    gets(p);
    while (p[i] != '\0')
    {
        if (p[i] >= '0' && p[i] <= '7')
            i++;
        else
            break;
    }
    if (p[i] == '\0')
        printf("\nOctal string");
    else
        printf("\nNot octal string");
}