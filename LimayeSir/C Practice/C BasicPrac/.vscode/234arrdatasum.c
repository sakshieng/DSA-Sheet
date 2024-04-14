#include <stdio.h>
int main()
{
    int x[10], i = 0;
    void display(int[], int);
    printf("\nData array:");
    for (i = 0; i < 10; i++)
        scanf("%d", &x[i]);
    display(x, 10);
    return 0;
}
int calctot(int k[], int n)
{
    int i = 1, tot = k[0];
    while (i < n)
    {
        tot += k[i++];
    }
    return tot;
}