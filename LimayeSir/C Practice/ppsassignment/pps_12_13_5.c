// 5) Write a program in C to check armstrong and perfect numbers using the function.
#include<stdio.h>
#include<stdlib.h>
 int checkArmstrong(int n1);
 int checkPerfect(int n1);
 int main()
 {
     int n1;
     system("cls");
     printf(" enter any number: ");
     scanf("%d",&n1);
    if(checkArmstrong(n1))
     {
         printf(" The %d is an Armstrong number.\n", n1);
     }
     else
     {
         printf(" The %d is not an Armstrong number.\n", n1);
     }
     if(checkPerfect(n1))
     {
         printf(" The %d is a Perfect number.\n\n", n1);
     }
     else
     {
         printf(" The %d is not a Perfect number.\n\n", n1);
     }
     return 0;
 }
 //check armstrong no
 int checkArmstrong(int n1) 
 {
     int ld, sum, num;
     sum = 0;
     num = n1;
     while(num!=0)  
     {  
         ld = num % 10;  
         sum += ld * ld * ld;
         num = num/10;  
     }
     return (n1 == sum);
 }
 //check perfect no
 int checkPerfect(int n1) 
 {
     int i, sum, num;
     sum = 0;
     num = n1;
     for(i=1; i<num; i++)  
     {  
         if(num%i == 0)  //calculate divisors
         {  
             sum += i;  //take their sum
         }  
     }
     return (n1 == sum);//check it's equal to original no
 }