#include<stdio.h>
void main()
{
    void wordcount();
    wordcount();
    return;
}
void wordcount()
{
    char p[40];
    int i=0,cnt=0;
    printf("Enter String");
    gets(p);
    while(p[i] != '\0')
    {
        if(p[i] == 32 && p[i+1] != 32)
        cnt++;
        i++;
    }
    printf("\nWords:%d",cnt);
    return;
}