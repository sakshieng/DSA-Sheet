#include<stdio.h>
int main()
{
    float sp,cp,profit;
    printf("enter selling price and profit of 15 objects\n");
    scanf("%f %f",&sp,&cp);
    cp=(sp-profit)/15;
    //cp=sp-profit imp
    printf("cost price of each object is %f\n",cp);
    return 0;

}
