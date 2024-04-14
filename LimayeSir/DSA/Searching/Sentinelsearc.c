#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// to check whether the target is in the list we are adding sentinel element and search the target
int main()
{
   int x[11],i;
   printf("\nSearch value: ");
   scanf("%d",&x[10]);
   for (i = 0; i < 10; i++)
   {
      scanf("%d",&x[i]);
   }
   for (i = 0; x[i] != x[10]; i++)
   {
      ;
   }
   if (i == 10)
   {
      printf("\nNot found");
   }
   else
   {
      printf("Found at pos:%d",i);
   }
   return 0;
}