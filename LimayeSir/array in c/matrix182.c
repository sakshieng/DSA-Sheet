#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x[4][3];
    int i, j;
    printf("\nMatrix\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nx[%d][%d]:", i, j);
            scanf("%d", &x[i][j]);
        }
    }
    printf("\nMatrix\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", x[i][j]);
        printf("\n");
    }
    printf("\nTranspose\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 4; i++)
            printf("%4d", x[i][j]);
        printf("\n");
    }
}