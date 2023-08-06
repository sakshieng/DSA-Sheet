#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[50],q[50];
   int i=0;
   gets(p);
   gets(q);
   while(p[i] != '\0')
   {
       if(p[i] == q[i])
       i++;
       else
       break;
   }
   q[i]='\0';
   if(p[i] == q[i])
   printf("Match\n");
   else
   printf("Non Match\n");
   return 0;
}   