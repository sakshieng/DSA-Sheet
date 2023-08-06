#include<stdio.h>
#include<stdlib.h>
int main()
{
    char p[40],q[40];
    int i=0;
    printf("\nString:\n");
    gets(p);
    {
        q[i]=p[i];
        i++;
         if(q[i]>=65 && q[i]<=90)
    {
        q[i]=q[i]+32;
    }
    }
   q[i]=='\0';
    puts(p);
    gets(q);
}