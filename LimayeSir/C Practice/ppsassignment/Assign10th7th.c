// print 2d array of 3*3 and print matrix 
#include<stdio.h>
#include<stdlib.h>
void main()
{
  int arr1[3][3],i,j;
  system("cls");
 printf("Input elements in the matrix :\n");
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
	      printf("element - [%d],[%d] : ",i,j);
	      scanf("%d",&arr1[i][j]);
      }
  }  
 printf("\nThe matrix is : \n");
  for(i=0;i<3;i++)
  {
      printf("\n");
      for(j=0;j<3;j++)
      printf("%d\t",arr1[i][j]);
  }
 printf("\n\n");
}