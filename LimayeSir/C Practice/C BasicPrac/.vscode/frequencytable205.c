//generate a frequency table for inputed string from a to z
#include<stdio.h>

void main()
{
    void ftable();
    ftable();
    return;
}
void ftable()
{
    char a[50];
    int i=0,cnt,arr[26];
    printf("\nEnter string:");
    gets(a);
    for(i=0; i<26 ; i++)
    arr[i]=0;
    for(i=0; a[i] != '\0' ;i++)
    {
        if(a[i] >= 65 && a[i] <= 90)
        cnt=a[i]-65;
        else
        {
            if(a[i] >= 97 && a[i] <= 122)
            cnt=a[i]-97;
            else
            continue;
        }
        arr[cnt]++;
    }
    printf("\nFreq Table\n");
    for(i=0; i<26 ;i++)
    printf("%c-%d\t",65+i,arr[i]);
    return;
}