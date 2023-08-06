//transpose of matrix
#include<stdio.h>
#include<stdlib.h>
int main()
 {  
    int rw, cl, i, j, mt[10][10], trv[10][10];
    system("cls");
    printf("Enter rows and columns :\n");
    scanf("%d%d", &rw, &cl);
    printf("Enter elements of the matrix\n");
    for (i= 0; i < rw; i++)
      for (j = 0; j < cl; j++)
         scanf("%d", &mt[i][j]);
   for (i = 0;i < rw;i++)
for (j = 0; j < cl; j++)
          trv[j][i] = mt[i][j];
    printf("transpose of the matrix:\n");
  for (i = 0; i< cl; i++) {
      for (j = 0; j < rw; j++)
         printf("%d\t", trv[i][j]);
     printf("\n");
  }
  return 0;
 }