#include <stdio.h>
#include <stdlib.h>
// Code by Sakshi:
// Probability search
int main()
{
    int x[10], i, j, sv, tmp;
    printf("\nEnter array data:");
    for (i = 0; i < 10; ++i)
        scanf("%d", &x[i]);
    while (1)
    {
        printf("\nSearch value:");
        scanf("%d", &sv);
        if (sv == 0)
            break;
        for (i = 0; i < 10; ++i)
        {
            if (x[i] == sv)
                break;
        }
        // most searched element will be at the leading
        if (i == 10)
            printf("%d data not found", sv);
        else
        {
            if (i != 0)
            {
                j = i - 1;
                tmp = x[j];
                x[j] = x[i];
                x[i] = tmp;
            }
            printf("\nRecord found");
        }
    }
    return 0;
}
// linked list most searched element should be at the begin