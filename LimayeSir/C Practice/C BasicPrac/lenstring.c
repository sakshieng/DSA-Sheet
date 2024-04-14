#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a[50];
    system("cls");
    int i=0;
    printf("\nEnter a string");
gets(a);
printf("\nString\n");
while(a[i]!='\0')
i++;
printf("\nLength :%d",i);

    return 0;
}