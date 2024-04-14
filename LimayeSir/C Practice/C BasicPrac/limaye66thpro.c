#include <stdio.h>
int main()
{
    int i = 1, x, max = 0;
    while (i <= 4)
    {
        printf("\nNo:");
        scanf("%d", &x);
        if (i == 1)
            max = x;
        else
        {
            if (x > max)
                max = x;
        }
        i++;
    }
    printf("\nmax:%d", max);
    return 0;
}