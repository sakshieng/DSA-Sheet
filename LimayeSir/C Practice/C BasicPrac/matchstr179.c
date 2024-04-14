#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[40],q[40];
   int i=0;
   printf("String 1:\n");
   gets(p);
   printf("String 2:\n");
   gets(q);
   while(p[i] == q[i])
   i++;
   if(p[i]==q[i])
   printf("Match");
   else
   printf("Not Match");
   return 0;
}