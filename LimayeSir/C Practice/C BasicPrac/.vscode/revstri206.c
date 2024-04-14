#include<stdio.h>
#include<string.h>
void main()
{
    void reverse();
    reverse();
    return;
}
void reverse()
{
    char a[50],tmp;
    int i=0,j=0;
    printf("\nString:");
    gets(a);
    j= strlen(a) - 1;
    while(i < j)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    puts(a);
    return;
}