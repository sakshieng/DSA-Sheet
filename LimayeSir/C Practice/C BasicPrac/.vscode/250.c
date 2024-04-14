#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   int x=10;
   printf("\nx:%d",x);
   printf("\nAddress:%u",&x);
   printf("\nValue:%d",*(&x));  
   return 0;
}