// 13)  Write a program in C to Calculate the length of the string using a pointer.
#include <stdio.h>
#include <stdlib.h>
int string_ln(char *);
int main()
{
   char str[20];
   int length;
   system("cls");
   printf("Enter any string :: ");
   scanf("%s", str);
   length = string_ln(str);
   printf("\nThe length of string [ %s ] is : %d\n", str, length);
   return 0;
}
int string_ln(char *p) /* p=&str[0] */
{
   int count = 0;
   while (*p != '\0')
   {
      count++;
      p++;
   }
   return count;
}