// program to copy file source file f1 to destination file f2
#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   FILE *fs,*fd;
   char ch;
   fs=fopen("abc.txt","r");
   if(fs==NULL)
   {
    printf("\nFile not found");
    return;
   }
   fd=fopen("pqr.txt","w");
   while(1){
    ch=fgetc(fs);
    if(feof(fs))
    break;
    fputc(ch,fd);
   }
   fclose(fs);
   fclose(fd);
   return 0;
}