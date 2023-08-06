#include <stdio.h>
int main() 
{
   int no;long int fact=1;
   printf("\nenter no");
   scanf("%d",&no);
   for(;(no>1);no--)
   fact*=no;
   printf("\nfactorials :%ld",fact);
   return 0;
}