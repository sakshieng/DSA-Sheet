#include <stdio.h>
int main() 
{
    int a,b,c;
    printf("Enter 3 nos.");
    scanf("%d %d %d",&a,&b,&c);
    if(a<b)
    {
        if(a<c)
        printf("\nMin:%d",a);
        else
        printf("\nMin:%d",c);
     }
     else
     {
         if(b<c)
         printf("\nMin:%d",b);
         else
         printf("\nMin:%d",c);
     }
     return 0;
}