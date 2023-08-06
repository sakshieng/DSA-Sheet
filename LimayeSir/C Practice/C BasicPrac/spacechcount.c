#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
   char p[N],ch;
   system("cls");
   int i=0,cnt=0;
   printf("\nString:");
   gets(p);
   while(p[i]!='\0')
   {
       ch=p[i];
       if(ch==' ')
       cnt++;
       i++;
   }
      printf("%d\n",cnt);
}
