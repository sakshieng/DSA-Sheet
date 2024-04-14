#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖

int main()
{
   char *p="coing";
   char c;
   int i;
   for(i=0;i<3;++i)
   {
    c=*p++;
   }
   printf("%c",c); 
   return 0;
}