#include <stdio.h>
int main()
{
    int i=1,j=1,n=5;
    printf("\nPattern\n");
    while(1)
    {
        printf("*");
        if(++j>n)
        {
            printf("\n");
            if(++i>1)
            break;
            j=1;
        }
    }
return 0;    
}
