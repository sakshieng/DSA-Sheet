// program to create a text file by writing lines
#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   char s[100];
   FILE *f1;
   f1=fopen ("line.txt","w");
   printf("\nEnter line---");
   while(1)
   {
    gets(s);
    if(strcmp(s,"stop.")==0)
    break;
    fputs(s,f1);
    fputs("\n",f1);
   }
   fclose(f1);
   return 0;
}