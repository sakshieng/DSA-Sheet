//15)  Write a program in C to find the maximum number between two numbers using a pointer.
#include<stdio.h>
#include<stdlib.h>
 void main()
 {
  int fno,sno,*ptr1=&fno,*ptr2=&sno;
  system("cls");
   printf(" enter  the first number : ");
   scanf("%d", ptr1);
    printf(" enter  the second  number : ");
    scanf("%d", ptr2); 
  if(*ptr1>*ptr2)
  {
   printf("\n\n %d is the maximum number.\n\n",*ptr1);
  }
  else
  {
   printf("\n\n %d is the maximum number.\n\n",*ptr2);
  }
 }