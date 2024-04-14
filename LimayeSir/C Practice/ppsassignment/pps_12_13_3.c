// 3) Write a program in C to swap two numbers using function.
#include<stdio.h>
#include<stdlib.h>
 int main()  
 {  
     int a, b;  
     system("cls");
     printf("Enter numbers to be swaped \n");  
     scanf("%d%d", &a, &b);  
     printf("\n\nBefore swapping: a = %d and b = %d\n", a, b);  
     swap(a, b);  
     return 0;  
 }   
 void swap(int x, int y)  
 {  
     int temp;  
     temp = x;  
     x    = y;  
     y    = temp;  
     printf("\nAfter swapping: a = %d and b = %d\n", x, y);  
 }