#include <stdio.h>
void main()
{
    int x[3][3], i, j, y[3][3], z[3][3];
    void display(int[][3], int, int);
    void add(int[][3], int[][3], int, int);
    system("cls");
    printf("\nMatrix x Data\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }
    printf("\nMatrix y Data\n");
    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }
    display(x, 3, 3);
    display(y, 3, 3);
    add(x, y, 3, 3);
    return;
}

void display(int k[][3], int r, int c)
{
    int i, j;
    printf("\nMartix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", k[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}
void add(int p[][3], int q[][3], int r, int c)
{
    int z[3][3], i, j;
    printf("\nAddition\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            z[i][j] = p[i][j] + q[i][j];
            printf("%4d", z[i][j]);
        }
        printf("\n");
    }
    return;
}