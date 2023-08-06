/*Batch A4 Sakshi Dhamapurkar 21510073*/
//Write a program in C to print all the alphabets using a pointer. 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char*c;
    system("cls");
    c=(char*)malloc(sizeof(char));
    printf("Uppercase Alphabets\n");
    *c='A';
    while(*c<='Z')
    {
      printf("%4c\t",*c);
      *c=*c+1;
    }
     printf("\n\n");
     printf("Lowercase Alphabets\n");
    *c='a';
    while(*c<='z')
    {
        printf("%4c\t",*c);
        *c=*c+1;
    }
    return 0;
}
