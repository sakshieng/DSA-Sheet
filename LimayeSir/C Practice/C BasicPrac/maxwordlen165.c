#include<stdio.h>
#include<stdlib.h>
int main()
{
    char p[50];
    system("cls");
    int len;
    int i=0,max=0,sp=0,ep=0;
    printf("\nString:\n");
    gets(p);
    while(p[i] != '\0')
    {
        if(p[i]==32 || p[i]=='\0')
        {
            ep=i;
            len=ep-sp;
            len>max;
            if(len>max)
            max=len;
            if(p[i] == '\0')
            break;
            sp=i+1;
        }
        i++;
    }
    printf("\nMax Length:%d",max);
}