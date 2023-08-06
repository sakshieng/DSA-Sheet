#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[40];
   system("cls");
   char q[40];
   int i=0;
   printf("\nString:\n");
   gets(p);
   while(p[i] != '\0')
   {
       q[i]=p[i];
       i++;
   }
   q[i]='\0';
   puts(q);
   return 0;
}