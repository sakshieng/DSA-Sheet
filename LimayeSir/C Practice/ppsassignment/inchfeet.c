#include <stdio.h>
#include<stdlib.h>
int main()
{
    float d1,d2;
    float result1;
    float result2;
    system("cls");
    printf("Enter distance in feets:%f",d1);
    scanf("%f",&d1);
    printf("Enter distance in inches:%f",d2);
    scanf("%f",&d2);
result1=d1+d2;
result2=d1+d2;
while(result2>=12.0)
{
result2=result2-12.0;
++result1;
}
printf("Enter the result %d %d",result1,result2);
return 0;
}