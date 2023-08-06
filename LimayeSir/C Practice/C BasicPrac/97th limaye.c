

#include <stdio.h>
int main() 
{
    int i,j,n,val=65;
    printf("\nLine Count\n");
    scanf("%d ",&n);
    printf("\nPattern\n");
        for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i+j<=n)
            printf(" ");
            else
        printf("%c",val++); 
        }
        printf("\n");   
    }
    return 0;
    //its important to write printf /n after the curly bracket
}