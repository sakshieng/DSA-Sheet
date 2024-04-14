#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int c[3][3],i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&c[i][j]);
        }
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                printf("%d",c[i][j]);
            }
        printf("\n");
    }
    if(c[i][j])
        printf("1\n");
    else
        printf("-1\n");
    
    return 0;
}
