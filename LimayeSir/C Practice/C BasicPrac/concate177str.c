#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("cls");
   int i=0;
   char p[20],q[20],r[40];
   printf("String 1:\n");
   gets(p);
   printf("String 2:\n");
   gets(q);
   strcpy(r , p);
   strcat(r , q);
   printf("Concatenated String:\n");
   puts(r);
  return 0;
}