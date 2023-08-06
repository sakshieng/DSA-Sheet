
include <stdio.h>
int main()
{
    int i=1,j=1,n=5;
    printf("\nPattern\n");
    while(1)
    {
        printf("*");
        if(++j>1)
        {
            printf("\n");
            if(++i>j)
            break;
            j=1;
        }
    }
return 0;    
}
