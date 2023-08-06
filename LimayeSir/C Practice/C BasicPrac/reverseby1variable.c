#include <stdio.h>
void main()
{
    system("cls");
    int i, n, tmp;
    printf("\nEnter the size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter %d elements:", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nArray is ..\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    for (i = 0; i < (n / 2); i++)
    {
        tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
    printf("\nArray after reversing...\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return;
}