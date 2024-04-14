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
        if (p[i] >= '0' && p[i] <= '9' || p[i] >= 'a' && p[i] <= 'z' || p[i] >= 'A' && p[i] <= 'Z')
            i++;
        else
            break;
    }
    if (p[i] == '\0')
        printf("\nAlphanumeric string");
    else
        printf("\nNot alphanumeric string");
}