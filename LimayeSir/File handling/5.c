// program to read file containing integer num
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   int no;
   FILE *f1;
   f1 = fopen("num.dat", "r");
   if (f1 == NULL)
   {
      printf("File not found");
      return;
   }
   printf("Data\n");
   while (1)
   {
      no = getw(f1);
      if (f1 == NULL)
      {
         printf("file not found");
         return;
      }
      printf("\nData");
      while (1)
      {
         no = getw(f1);
         if (feof(f1))
            break;
         printf("%d", no);
      }
      fclose(f1);
   }
      return;
}














