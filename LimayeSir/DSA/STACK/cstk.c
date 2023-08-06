#include <stdio.h>
#include "cstk.h"
#include <stdlib.h>
// Code by Sakshi

int main()
{
    STK s;
    init(&s);
    char p[100];
    int i = 0, flag = 0;
    char ch;
    printf("Enter expression: ");
    scanf("%s", p); // no space allowed in expression
    while (p[i] != '\0')
    {
        if (p[i] == '(')
        {
            push(&s, p[i]);
            flag = 1;
        }
        else
        {
            if (p[i] == ')')
            {
                if (isEmpty(&s))
                    break;
                else
                    pop(&s);
            }
        }
        i++;
    }
    if (flag == 0)//no left parenthesis (left mhnje flag=1)
    {
        if(p[i] != '\0')//ek right milala ani break zhala
            printf("\nUnderflow....Extra at right");
        else
            printf("\nNo parenthesis");            
    }
    else
    {
        if (isEmpty(&s))
        {
            if (p[i] == '\0')
                printf("\nBalanced parenthesis");
            else
                printf("\nUnbalanced....Extra at right");
        }
        else
            printf("\nUnbalanced....Extra at left");
    }
}
