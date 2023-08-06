#include <stdio.h>
int main() 
{
    int i=1,j=1,n=5;
    while(i<=n)
    {
        for(j=1;j<=n;j++);
        printf("$");
        printf("\n");
        i++;
    }
    return 0;
}