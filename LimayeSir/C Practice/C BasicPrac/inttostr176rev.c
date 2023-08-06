#include<stdio.h>
#include<stdlib.h>
//integer to string without using sprintf fun^c
int main()
{
   char p[50],ch;
   int no,dig,i=0,j=0;
   printf("\nString:\n");
   scanf("%d",&no);
   while(no>0)
   {
      dig=no%10;
      ch=(char)(48+dig);//type casting
      p[j]=ch;
      no/=10;
      j++; 
   }
   p[j]='\0';
    for(; j>=0; i++,j--)
   {
      ch=p[i];
      p[i]=p[j];
      p[j]=ch;
   }
   puts(p);
   return 0;
}