#include <stdio.h>
int main() 
{
    int units;
    float bill;
    printf("\nenter no of units");
    scanf("%d",&units);
    //units>=100 then per unit 90 paisa,less than 100 then per unit 80 paisa
    if(units>=100)
    {
        bill=0.9*units;
    }
    else
    {
        bill=0.8*units;
    }
    printf("\ntotal bill to be paid is:%f",bill);
    return 0;
     

}
