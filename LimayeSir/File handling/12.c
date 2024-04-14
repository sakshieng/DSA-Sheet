#include<stdio.h>
#include "STU.h"
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   FILE *fs;
   int no;
   STU s;
   fs=fopen("STU.dat","wb");
   while (1)
   {
    printf("\nRoll no:");
    scanf("%d",&no);
    if(no==0)
    break;
    input(&s,no);
    fwrite(&s,sizeof(STU),1,fs);
   }
   fclose(fs);
   return 0;
}