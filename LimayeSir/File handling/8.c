// program to read file line by line
#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   char s[100];
   FILE *f1;
   f1=fopen("line.txt","r");
   if(f1==NULL)
   {
    printf("\nFile not found");
    return;
   }
   printf("\nFile data");
   while(1)
   {
    fgets(s,100,f1);
    if(feof(f1))
    break;
    puts(s);
   }
   fclose(f1);
   return 0;
}