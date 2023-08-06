#include<stdio.h>
#include<stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
   int isBinary();
   if(isBinary() == 0)
   printf("Not binary");
   else
   printf("Binary");
   return 0;
}
int isBinary()
{
    int i=0;
    char p[20];
    printf("String\n");
    scanf("%s",p);
    while (p[i]!='\0')
    {
        if(p[i]=='0'|| p[i]=='1')
        i++;
        else
        break;
    }
    return(p[i]=='\0');
}