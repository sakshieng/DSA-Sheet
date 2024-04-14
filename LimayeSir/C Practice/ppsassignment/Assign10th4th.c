
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    system("cls");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int max=a[0],min=a[0];
    for (int i = 0; i < n; i++)
    {
         if (a[i]>max)
         {
             max=a[i];
         }
         if (a[i]<min)
         {
             min=a[i];
         }
        
    }
    printf("max is %d and min is %d",max,min);
    
}