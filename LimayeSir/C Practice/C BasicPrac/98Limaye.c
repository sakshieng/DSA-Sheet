#include<stdlib.h>
#include <stdio.h>
int main() 
{
    int i,j,n,val=65;
    system("cls");
    printf("\nLine Count\n");
    scanf("%d ",&n);
    printf("\nPattern\n");
        for(i=1;i<=n;i++)
    {
        for(j=1,val=65;j<=n;j++)
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