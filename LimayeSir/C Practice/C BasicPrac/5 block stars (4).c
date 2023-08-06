

nclude <stdio.h>
int main()
{
    int i=1,j=1,n=5;
    printf("\nPattern\n");
    while(1)
    {
        printf("*");
        if(++j>i)
        {
            printf("\n");
            if(++i>n)
            break;
            j=1;
        }
    }
return 0;    
}
