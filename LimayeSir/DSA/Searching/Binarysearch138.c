#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x[10];
    system("cls");
    int i=0,l=0,r=9,sv,mid;
    while(i<10)
    {
        printf("\nNo.");
        scanf("%d",&x[i]);
        if(i && x[i]<x[i-1])
        {
            printf("\nInvalid Value");
            continue;
        }
        i++;
    }
            printf("\nEnter Search Value");
            scanf("%d",&sv);
            do
            {
                mid=(l+r)/2;
                if(x[mid]==sv)
                break;
                if(sv<x[mid])
                r=mid-1;
                else
                r=mid+1;
            }while (i<=r);
            if(l>r)
            printf("\nNot found");
            else
            printf("\nFound");
    
}