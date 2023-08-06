#include<stdio.h>
#include<stdlib.h>
#define N 20
int main()
{
    char t[N];
    int i=0,cnt=0;
    printf("\nString:");
    gets(t);
    while(1)
    {
        if(t[i]==32 && t[i+1]!=32)
        cnt++;
        else
        {
            if(t[i]=='\0')
            {
                cnt++;
                break;
            }
        }
        i++;
    }
    printf("\nWord count:%d",cnt);
}