#include<stdio.h>

int main()
{
    int i=10;
    char name[6] = {'h','a','c','k','e','r'};
    
    scanf("%d", (int *)(name+6));
    
    printf("%d",i);
    
    return 0;
}