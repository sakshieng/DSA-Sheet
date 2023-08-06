#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("cls");
   char p[40],q[40];
   int i=0;
   printf("\nString:\n");
   gets(p);
   while(p[i] != 0)
   {
       if(p[i]>=97 && p[i]<=122)
       q[i]=p[i]-32;
       else
       q[i]=p[i];
       i++;//imp most imp
   }
   q[i]='\0';
   
   puts(q);
   return 0;
}