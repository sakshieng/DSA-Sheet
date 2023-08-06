 #include <stdio.h>
int main()
{
    int i,j,n;
    printf("Line count:\n");
    scanf("%d",&n);
    printf("Pattern\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
    if(j==1||i==n||i==j)
    printf("*");
    else
    printf(" ");
        }
        printf("\n");
    }
 return 0;
}