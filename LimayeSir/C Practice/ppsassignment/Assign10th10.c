//length of string 150th prog
 #include<stdio.h>
 #include<stdlib.h>
void main()
 {
   char s[50];
   system("cls");
      int i, l = 0;
 
    printf("enter a string : ");
     scanf("%s", s);
 
   for (i = 0; s[i] != '\0'; i++)
  {
     l++;
  }
    
   printf("So, the length of the string %s is : %d\n\n", s, l);
}