#include<stdio.h>
void main()
#define N 100
{
    void upper();
    upper();
    return;
}
void upper()
{
    char a[N];
    int i=0;
    printf("\nEnetr String:");
    gets(a);
    while(a[i] != '\0')
    {
        if(a[i]>=97 && a[i]<=122)
        {
            a[i]=a[i]-32;
            i++;
        }
        else
        break;
    }
    puts(a);
    return;
}