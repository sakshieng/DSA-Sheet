#include<stdio.h>
#include<stdlib.h>
#define N 50
int main()
{
   char p[N];
   int sp=0;
   int i=0;
   system("cls");
   printf("\nString:\n");
   gets(p);
    while(1) //indefinite loop always true
    {
        if(p[i]==32 || p[i]=='\0')
        {
            printf("%d\n",sp);
            if(p[i]=='\0')
            break;
            sp=i+1;
        } 
        i++;
    }
    return 0;
}