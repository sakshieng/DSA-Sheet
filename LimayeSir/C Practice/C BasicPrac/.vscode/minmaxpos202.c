//func to update array of 10 integers and find min max element's position
#include<stdio.h>

#include<stdlib.h>
void main()
{
    void minmaxpos();
    minmaxpos();
    return;
}
void minmaxpos()
{
    int i=0,no,xmin,xmax;
    system("cls");
    int x[10];
    for(; i<10 ; i++)
    {
        printf("\nEnter No:");
        scanf("%d",&x[i]);//imp to take input
        if(i==0)
        {
            xmin=0;
            xmax=0;
        }
        else
        {
            if(x[i] < x[xmin])
            xmin=i;
            else
            {
                if(x[i] > x[xmax])
                xmax=i;
            }
        }
    }
    printf("\nMax value:%d \nPosition:%d",x[xmax],xmax);
    printf("\nMin value:%d \nPosition:%d",x[xmin],xmin);
    return ;
}