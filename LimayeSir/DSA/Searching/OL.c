#include <stdio.h>
#include <stdlib.h>
// Code by Sakshi:

int main()
{
    int x[11], i = 0;
    //    ascending order data accept
    while (i < 10)
    {
        printf("\nEnter data:");
        scanf("%d", &x[i]);
        if (i) // i chi value 0 astana block mdhe yenar nhi
        {
            if (x[i] < x[i - 1])
            {
                printf("\nInvalid data:");
                break;
            }
        }
        i++;
    }
    printf("\nEnter search value:");
    scanf("%d", &x[i]); // sentinel element
    for (i = 0; x[i] < x[10]; ++i)
        ;
    if (i == 10)
        printf("\nNot found");
    else
        //break either jast value brobr compare or found
    {
        if(x[i]==x[10])
            printf("\nFound");
        else
            printf("\nNot found");//SV peksha mothi value input keliy    
    }      
    return 0;
}