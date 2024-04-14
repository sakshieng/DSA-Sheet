#include<stdio.h>
int main()
{
    int day;
    printf("enter day no.\n");
    scanf("%d",&day);
    switch (day)
    {
    case 1:
    printf("its monday\n");
    break;
    case 2:
    printf("its tuesday\n");
    break;
    case 3:
    printf("its wednesday\n");
    break;
    case 4:
    printf("its friday\n");
    break;
    case 5:
    printf("its thursday\n");
    break;
    case 6:
    printf("its saturday\n");
    break;
    case 7:
    printf("its sunday\n");
    break;
    default:
    printf("invalid entry\n");
    
    }
    return 0;
}