#include <stdio.h>
#include <stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖

int main()
{
    int x[10], val, i, j;
    printf("\nEnter data:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
        for (j = i - 1; j >= 0 && val < x[j]; j--)
            x[j + 1] = x[j];
        x[j + 1] = val;
    }
    printf("\nData:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%4d", x[i]);
    }
    return 0;
}