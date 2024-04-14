#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("cls");
   char p[50];
   int n;
   printf("\nEnter No:");
   scanf("%d",&n);
   sprintf(p,"%d",n);
   puts(p);
   return 0;
}