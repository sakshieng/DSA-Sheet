// 10) Write a program in C to find the sum of digits of a number using recursion.
#include<stdio.h>
#include<stdlib.h>
 int main()
 {
   int Number, Reminder, Sum=0;
system("cls");
   printf("\n Please Enter any number\n");
   scanf("%d", &Number);
   while(Number > 0)
   {
      Reminder = Number % 10;
      Sum = Sum+ Reminder;
      Number = Number / 10;
   }
   printf("\n Sum of the digits  = %d", Sum);
   return 0;
 }