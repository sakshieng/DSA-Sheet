#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("cls");
   char p[40],q[40];
   int i=0;
   printf("String:\n");
   gets(p);
   while(p[i] != '\0')
   {
       if(p[i]>=65 && p[i]<=90)
       q[i]=p[i]+32;
       else
       q[i]=p[i];
       i++;
   }
   q[i]='\0';
   puts(q);
   return 0;
}