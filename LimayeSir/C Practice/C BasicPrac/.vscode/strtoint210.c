//write a function to convert a inputed string into integer
#include<stdio.h>
#include<string.h>
void main()
{
    void tointeger();
    tointeger();
    return;
}
void tointeger()
{
    char a[50],ch;
    int i=0,val=0,dig,factor=1;
    printf("\nEnter integer string: ");
    gets(a);
    i= strlen(a) - 1;
    while(i>=0)
    {
        if(a[i] >= 48 && a[i] <= 57)//ascii value
        {
            dig= a[i] - 48;
            val=factor*dig + val;
            factor*=10;
            i--;
        }       
        else
        break; 
    }
    if(i>0)
    printf("\nInvalid input");
    else
    printf("\nNo: %d",val);
    return;
}