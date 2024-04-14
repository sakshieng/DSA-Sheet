#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// Sequential/Linear search
//here the data should be in asending order
int main()
{
   int x[10];
   int sv,i;
   printf("\nEnter data:\n");
   for ( i = 0; i < 10; i++)
   {
    scanf("%d",&x[i]);
   }
   printf("\nEnter search value: ");
   scanf("%d",&sv);
   for ( i = 0; i < 10; i++)
   {
    if (x[i] == sv)
        break;
   }
   if(i == 10)
    printf("\nNot found");
   else
    printf("\nFound at position:%d",i); 
   return 0;
}