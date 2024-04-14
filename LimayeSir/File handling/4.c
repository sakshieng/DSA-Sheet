// program to create file containing integer no.
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   int no;
   FILE *f1;
   f1 = fopen("num1.dat", "w");
   printf("Enter numbers\n");
   while (1)
   {
      scanf("%d", &no);
      if (no == 0)
         break;
      putw(f1);
   }
   fclose(f1);
   return 0;
}