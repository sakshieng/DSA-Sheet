#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
   char p[N];
   int sp=0,ep=0;
   int i=0;
   system("cls");
   printf("\nString:\n");
   gets(p);
    while(1) 
    {
        if(p[i]==32 || p[i]=='\0')
        {
            ep=i-1;
            printf("%d\n",ep-sp+1);//we can use ep=i then ep-sp ---> length of word
            if(p[i]=='\0')
            break;
            sp=i+1;
        } 
        i++;
    }
    return 0;
}