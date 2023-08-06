#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
   system("cls");
   int i=0;
   int cnt=0;
   char p[N];
   printf("\nString:\n");
   gets(p);
   while(p[i] != '\0')
   {
   if(cnt%2 == 1)
   {
       if(p[i]>=97 && p[i]<=122)
       p[i]=p[i]-32;
   }   
       else
       {
           if(p[i]>=65 && p[i]<=90)
           p[i]=p[i]+32;
       }
           if(p[i]==32)
           cnt++;
           i++;
   }
   puts(p);
   return 0;
}