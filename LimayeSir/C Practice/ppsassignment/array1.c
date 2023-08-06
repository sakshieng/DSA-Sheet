#include <stdio.h>
#include<stdlib.h>
int main()
{
    int x[10];
    int i = 0;
    system("cls");
    printf("\narray:");
    while (i < 10)
    {
        printf("\nx[%d]:", i);
        scanf("%d", &x[i]);
        if (x[i] > 0)
            printf("Positive integer\n");
        else
        {
            if (x[i] < 0)
                printf("Negative integer\n");
            else
                printf("Zero integer");
        }
        i++;
    }
}