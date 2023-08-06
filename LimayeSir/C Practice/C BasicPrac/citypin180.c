#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[40],q[40];
   int i=0;
   long int pno;
   printf("\nCity Name:");
   gets(p);
   printf("\nPin Code:");
   scanf("%ld",&pno);
   sprintf(q,"%s-%d",p,pno);
   puts(q);
   return 0;
}