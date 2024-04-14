//write a program to display reverse of inputed string
#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
    char p[N];
    int i=0;
    system("cls");
    printf("\nString:");
    gets(p);
    while(p[i]!='\0')
    i++;
    printf("\nOutput\n");
    for(--i;i>=0;i--)
    printf("%c",p[i]);
    
}