#include <stdio.h>
#include <stdlib.h>
#define M 5
// Code by Sakshi:
//  enter data in asecending data ithe array mdhe data input krtana fibonacci series che index vaprtoy
int main()
{
    int i = 0, f1, first, f2, mid, index, sv, x[M];
    while (i < 10)
    {
        printf("\nEnter no:");
        scanf("%d", &x[i]);
        if (i > 0)
        {
            if (x[i] < x[i - 1])
            {
                printf("\nInvalid data");
                continue;
            }
        }
        i++;
    }
    printf("\nSearch value:");
    scanf("%d",&sv);
    f1=1,f2=0,mid=2;
    while (f1 < M)
    {
        f1=f1+f2;
        f2=f1-f2;
        mid++;
    }
    f2=f1-f2;
    f1=f1-f2;
    mid--;
    first=0;
    while (mid > 0)
    {
        index=first+f1;
        if(index >= M || sv < x[index])
        {
            mid--;
            f2=f1-f2;
            f1=f1-f2;
        }
        else
        {
            if(sv == x[index])
                break;
            else
            {
                first=index;
                mid -= 2;
                f1=f1-f2;
                f2=f2-f1;
            }    
        }
    }
    if(mid > 0)
        printf("\nFound at position:%d",index);
    else
        printf("\nNot found");    
    return 0;
}