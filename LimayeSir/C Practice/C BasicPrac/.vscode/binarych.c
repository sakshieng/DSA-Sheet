#include<stdio.h>
void main()
{
    int isbinary();
    isbinary();
    char res;
    if(res == 1)
    printf("Binary Ch");
    else
    printf("Not binary ch");
    return;
}
int isbinary()
{
      char res;
    char ch;
    scanf("%c",&ch);
    if(ch == '1' || ch == '0')
    res=1;
    else
    res=0;
    return res;
}