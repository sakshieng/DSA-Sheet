#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("cls");
   char a[50];
   int i=0,flg=0;
   printf("\nString:\n");
   gets(a);
   while(a[i] != '\0')
   {
       if(flg==0)
       {
           if(a[i]>=97 && a[i]<=122)
           a[i]=a[i]-32;
           flg=1;
       }
       else
       {
           if(a[i]==32)
           flg=0;
          else
       {
           if(a[i]>=65 && a[i]<=90)
           a[i]=a[i]+32;
       }
       }
   }
   i++;
   gets(a);
   return 0;
}