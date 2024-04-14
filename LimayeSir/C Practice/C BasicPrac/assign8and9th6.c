#include<stdio.h>
int main()
{
    int i,j,x=1;
    printf("\nPattern");
    scanf("%d",&x);
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(i>=j)
            {
                printf("%d ",x);
            x++;
            }
        }
        printf("\n");
    }
}