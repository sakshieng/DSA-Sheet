#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
//Worst case TC-->O(n^2)
int main()
{
   int x[10],i,j,tmp,flg;
   printf("\nEnter array data:\n");
   for (i = 0; i < 10; i++)
   {
    scanf("%d",&x[i]);
   }
   printf("Before sorting:\n");
   for ( i = 0; i < 10; i++)
   {
    printf("%4d",x[i]);
   }
   for ( i = 0; i < 9; i++)
   {
    flg=0;
    for ( j = 0; j < 9-i; j++)
    {
        if (x[j] > x[j+1])
        {
            tmp=x[j];
            x[j]=x[j+1];
            x[j+1]=tmp;
            flg=1;
        }
    }
    if(flg == 0) break;
   }
   printf("\n");
   printf("After sorting:\n");
   for ( i = 0; i < 10; i++)
   {
    printf("%4d",x[i]);
   }
   return 0;
}