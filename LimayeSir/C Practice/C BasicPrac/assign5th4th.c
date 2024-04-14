#include<stdio.h>
#include<math.h>
int main()
{
    float SP,CP,PR;
    printf("enter selling prize and profit on 15 itmes\n",SP,CP);
    scanf("%f %f",&SP,&CP);
    CP=SP-PR;
    printf("cost prize of 15 item is=%f\n",CP);
    //cost prize of one item
    CP=CP/15;
    printf("cost prize of one item is=%f",CP);
    return 0;
}