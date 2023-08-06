#include<stdio.h>
int main()
{
    int t;
    printf("\nenter a temperature");
    scanf("%d",&t);
    if(t<0)
    printf("\nfreezing weather");
    else
    {
        if(t>0 && t<=10)
        printf("\nvery cold weather");
        else
        if(t>=20 && t<30)
        printf("\nnormal in temp");
        else
        if(t>=30 && t<40)
        printf("\nits hot");
        else
        if(t>=40)
        printf("\nIts very hot");
        else
        printf("\nother"); 
    }
    return 0;

}