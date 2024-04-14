//write a program to reverse a string
#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
    char p[N];
    int i=0,j=0;
    system("cls");
    char tmp;
    printf("\nString:");
    gets(p);
    while(p[j]!='\0')
    j++;
    for(--j;i<j;i++,j--)
    {
        tmp=p[i];
        p[i]=p[j];
        p[j]=tmp;
    }
    puts(p);
    
 }