#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x[3][3], i, j;
    void display(int[3][3], int, int);
    // we have to give no of segments hence write 3 in square bracket
    system("cls");
    printf("\nMatrix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            scanf("%d", &x[i][j]);
    }
    display(x, 3, 3);
    return 0;
}
void display(int k[3][3], int r, int c)
{
    int i, j;
    printf("\nMatrix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", k[i][j]);
        printf("\n");
    }
}