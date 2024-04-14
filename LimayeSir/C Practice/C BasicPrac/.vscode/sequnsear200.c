//func to write sequential search
#include<stdio.h>

void main()
{
    void sequentialsearch();
    sequentialsearch();
    return;
}
void sequentialsearch()
{
    int i=0,x[10],sv;
    printf("\nArray Data ");
    for(i=0 ; i<10 ;i++)
    scanf("%d",&x[i]);
    printf("\nEnter Search Value ");
    scanf("%d",&sv);
    for(i=0 ; i<10 ; i++)
    {
        if(x[i] == sv)
        break;
    }
    if(i==10)
    printf("\nNot Found");
    else
    printf("\nFound");
    return;
}