//addition of matrix
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int  a[3][3]={1,2,3,1,0,1,2,0,0};
int  b[3][3]={2,1,0,2,3,2,1,3,3};
system("cls");
 int c[3][3],i,j; 
 printf("addition of a&b\n");
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      c[i][j]=a[i][j]+b[i][j];
      printf("%d ",c[i][j]);
    } 
    printf("\n");
  }
  return 0;
}