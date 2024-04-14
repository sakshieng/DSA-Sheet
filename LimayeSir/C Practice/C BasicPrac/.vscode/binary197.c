#include<stdio.h>
void main()
{
    void binarystring();
    binarystring();
    return;
}
void binarystring()
{
    char a[50];
    int i=0,cnt=0;
    printf("\nString:");
    gets(a);
    while(a[i] != '\0')
    {
        if(a[i] < '0' || a[i] > '1')
        break;
        i++;
    }
    if(a[i] == '\0')
    printf("Valid ");
    else
    printf("Invalid ");
    printf("Binary string");
}