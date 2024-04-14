#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[20],q[20],r[40];
   int i=0,j=0;
   system("cls");
   printf("String 1:\n");
   gets(p);
   printf("String 2:\n");
   gets(q);
   while(p[i] != '\0')
   {
       r[i]=p[i];
       i++;
   }
   while(q[j] != '\0')
   {
       r[i]=q[j];
       i++;
       j++;
   }
   r[i]='\0';
   puts(r);
   return 0;
}