#include<stdio.h>
 int main()
//use of conditinal operator by if ...else for no is prime or not
{
    int no;
    printf("\n enter a no:");
    scanf("%d",&no);
    int count=0;
    for(int i=2;i<no;i++)
    {
        if(no%i==0)
        count++;
    }
    if(count!=0)
    {
        printf("Not a prime no\n");
    }
    else
    {
        printf("Prime number\n");
    }
    return 0;

}
