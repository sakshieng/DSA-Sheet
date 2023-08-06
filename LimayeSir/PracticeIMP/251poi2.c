#include <stdio.h>
void main()
{
    int x = 10;
    int *y;
    y = &x;
    printf("\n%d", x);
    printf("\n%u", &x);
    printf("\n%d", *(&x));
    printf("\n%d", y);
    printf("\n%d", &y);
    printf("\n%d", *(*(&y)));
    printf("\n%d", *(&y));
    *y = *y + 5;
    printf("\n%d", x);
}