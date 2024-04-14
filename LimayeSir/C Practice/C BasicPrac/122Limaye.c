#include<stdio.h>
int main()
{
    int mno,days;
    system("cls");
    printf("\nEnterNo");
    scanf("%d",&mno);
    if(mno<1 || mno>12)
    printf("Invalid Input");
    else
    {
        switch(mno)
        {
            case 2:
            days=28;
            break;
            case 4:
            case 6:
            case 9:
            case 11:
            days=30;
            break;
            default:
            days=31;
        }
        printf("\nDays %d in Month:%d",days,mno);
    }
}