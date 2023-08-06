#include <stdio.h>
#include <stdlib.h>
#define M 10
// merge sort algo is based on divide and conquer algo Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation
//  T(n) = 2T(n/2) + θ(n)
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
void input(int *a)
{
    int i = 0;
    printf("\nData:\n");
    while (i < M)
    {
        scanf("%d", a + i);
        i++;
    }
}
void display(int *a, int flg)
{
    int i = 0;
    if (flg == 0)
        printf("Before sorting\n");
    else
        printf("\nAfter sorting\n");
    while (i < M)
    {
        printf("%4d", a[i++]);
    }
}
int main()
{
    int x[M], i, j, k, l1, u1, l2, u2, size = 1;
    int tmp[M]; // we are creating one temporary array so that we can
    input(x);
    display(x, 0);
    while (size < M)
    {
        l1 = 0, k = 0;
        while (l1 + size < M)
        {
            l2 = l1 + size;
            u1 = l2 - 1;
            if (l2 + size < M)
                u2 = l2 + size - 1;
            else
                u2 = M - 1;
            for (i = l1, j = l2; i <= u1 && j <= u2; k++)
            {
                if (x[i] < x[j])
                    tmp[k] = x[i++];
                else
                    tmp[k] = x[j++];
            }
            for (; i <= u1; i++)
                tmp[k++] = x[i];
            for (; j <= u2; j++)
                tmp[k++] = x[j];
            l1 = u2 + 1;
        }
        for (i = l1; i < M; i++)
            tmp[k++] = x[i];
        for (i = 0; i < M; i++)
            x[i] = tmp[i];
        size *= 2;
    }
    display(x, 1);
    return 0;
}