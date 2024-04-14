#include<stdio.h>
#include <stdlib.h>
int main()
{
    int arr1[3][3], i, j;
    system("cls");
    printf("Enter elements in matrix\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nelement [%d][%d] :", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nThe matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d\t", arr1[i][j]);
        printf("\n");
    }
}