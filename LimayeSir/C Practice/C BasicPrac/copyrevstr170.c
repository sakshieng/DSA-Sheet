#include<stdio.h>
//write a program to copy reversed string
#include<stdlib.h>
#define N 50
int main()
{
   system("cls");
   char a[N],b[N];
   int i=0,j=0;
   printf("\nSource string:");
   gets(a);
   j=strlen(a);//length of string
   // or we can write
   //while(a[j] != '\0')
   //j++;
   for(b[j--]='\0'; j>=0 ; j--,i++)
   b[j]=a[i];
   puts(a);
   puts(b);
   return 0;
}