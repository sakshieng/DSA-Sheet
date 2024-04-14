 // 13) Write a program in C to show the basic declaration of pointer.
 #include<stdio.h>
 #include<stdlib.h>
 int main()
 {
     int a; 
     system("cls");
     a = 10;
     int *p = &a;
     printf("%d\n", *p);  
     printf("%d\n", *&a);  
     printf("%u\n", &a);    
     printf("%u\n", p);     
     printf("%u\n", &p); 
     return 0;
 }