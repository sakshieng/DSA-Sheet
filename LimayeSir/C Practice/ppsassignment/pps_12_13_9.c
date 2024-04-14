 // 9) Write a program in C to find GCD/HCF of two numbers using recursion.
#include<stdio.h>
#include<stdlib.h>
 int hcf(int n1, int n2);
 int main() 
 {
     int n1, n2;
     system("cls");
     printf("Enter two positive integers: ");
     scanf("%d %d", &n1, &n2);
     printf("G.C.D of %d and %d is %d.", n1, n2, hcf(n1, n2));
     return 0;
 }
 int hcf(int n1, int n2)
  {
     if (n2 != 0)
         return hcf(n2, n1 % n2);
     else
         return n1;
  }