#include<stdio.h>
#include<stdlib.h>
int main()
#define N 50
{
   system("cls");
   char p[N];
   int i=0,sp=0,ep=0;
   char ch;
   printf("\nString:\n");
   gets(p);
   while(1)
   {
       if(p[i]==32 || p[i]=='\0')
       {
           ep=i-1;
           while(sp<ep)
           {
               ch=p[sp];
               p[sp]=p[ep];
               p[ep]=ch;
           }
           sp++;
           ep--;
           if(p[i]=='\0')
           break;
           sp=i+1;
       }
       i++;
   }
   return 0;
}