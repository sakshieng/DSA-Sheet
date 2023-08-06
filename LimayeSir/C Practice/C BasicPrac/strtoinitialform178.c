#include<stdio.h>
#include<stdlib.h>
int main()
{
   char p[40],q[40];
   int i=0,j=0,sp=0;
   printf("\nEnter full name:");
   gets(p);
   while(p[i] != '\0')
   {
       if(p[i]==32)
       {
           q[j++]=q[sp];
           q[j++]='.';
           sp=i+1;
       }
       i++;
   }
   while(p[sp] != '\0')
   q[j+1]=p[sp+1];
   q[j]='\0';
   puts(p); puts(q);
   return 0;
}