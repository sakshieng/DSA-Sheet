#include <stdio.h>
#include <stdlib.h>
// Code by Sakshi:
// Binary search
int main()
{
    int x[10], i=0, sv, l=0, r=9;
    int mid = (l + r) / 2;
    printf("\nEnter array data:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &x[i]);
    while (i < 10)
    {
        if (x[i] < x[i - 1])
        {
            printf("\nInvalid data:");
            continue;
        }
        i++;
    }
    printf("\nEnter search value:\n");
    scanf("%d", &sv);
    do
    {
        if(x[mid] == sv)
        break;
        if(sv < x[mid])
        r=mid+1;
        else
        l=mid-1;
    } while (i <= r);//no of iterations should be less than right
    if(l > r)
        printf("\nNot found");
    else
        printf("Found at %d position",x[mid]);    
    return 0;
}