#include <stdio.h>
// when we input no other than
#include <stdlib.h>
int main()
{
    int x[10], i = 0, val;
    system("cls");
    while (i < 5)
    {
        scanf("%d", &val);
        if (i == 0)
            x[i] = val;
        else
        {
            if (val < x[i - 1])
            {
                printf("\nInvalid Input");
                continue;
            }
            x[i] = val;
        }
        i++;
    }
    printf("\nData\n");
    for (i = 0; i < 5; i++)
        printf("%5d", x[i]);
    return 0;
}