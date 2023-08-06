#include<stdio.h>
#include<stdlib.h>
int main()
{
   int x[10][10],y[10][10];
   int i,j,tmp,r,c;//r==rows,c==coulmn
   system("cls");
   printf("\nEnter rows:");
   scanf("%d",&r);
   printf("\nEnter coulumns:");
   scanf("%d",&c);
   printf("\nMatrix\n");
   for(i=0 ; i<r ;i++)
   {
     for(j=0 ; j<c ;j++) 
     scanf("%d",&x[i][j]); 
   }
   printf("\nSource\n");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           printf("%4d",x[i][j]);
           y[j][i] = x[i][j];
       }
   }
   printf("\nDestination\n");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       printf("%4d",y[i][j]);
       printf("\n");
   }
   return 0;
}