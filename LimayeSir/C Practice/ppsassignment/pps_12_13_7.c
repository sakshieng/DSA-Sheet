 // 7) Write a program in C to print first 50 natural numbers using recursion.
 #include<stdio.h>
 #include<stdlib.h>
 int  numPrint(int);
 int main()
 {
     int n = 1;
     system("cls");
 	 printf(" The natural numbers are :");
     numPrint(n);
     printf("\n\n");
     return 0;
 }
 int numPrint(int n)
 {
     if(n<=50)
     {
          printf(" %d ",n);
          numPrint(n+1);
     }
 }