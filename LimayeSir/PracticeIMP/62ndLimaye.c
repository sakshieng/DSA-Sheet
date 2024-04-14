#include <stdio.h>
int main()
{
    int i = 1, j = 1, n = 5;
    printf("\nPattern\n");
    while (1)
    {
        printf("1");
        if (++j > i)
        {
            printf("\n");
            if (++i > n)
                break;
            j = 1;
            j++;
        }
    }
    return 0;
}
