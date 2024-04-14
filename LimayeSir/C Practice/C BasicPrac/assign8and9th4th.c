#include <stdio.h>
int main()
{
    int n, i, a;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("\nMultiplication table from 1 to %d\n\n",n);
    for (i = 1; i <= n; i++)
    {
        for (a = 1; a <= 10; a++)
        {
            printf("%dx%d = %d, ", i, a, i * a);
        }
        printf("\n\n");
    }
    return 0;
}