#include<stdio.h>
void main()
{
    int oddeven();
    int res;
    res=oddeven();
    if(res == 1)
    printf("\nOdd no");
    else
    printf("\nEven no");
    return;
}
int oddeven()
{
    int no;
    printf("\nEnter no");
    scanf("%d",&no);
    return(no % 2);
}