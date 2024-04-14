#include<stdio.h>
#include "myfun.h"
//to check odd even
int oddeven(int n)
{
    return n%2;
}
//to compute digit sum
int digitsum(int no)
{
    int tot=0;
    while(no > 0)
    {
      tot+=(no%10);
      no/=10;
    }
    return tot;
}
//to calculate nth element of Fibonacci series
int fibo(int n)
{
    int i=1,a=-1,b=1,c;
    while(i < n)
    {
        c=a + b;
        a=b;b=c;
        i++;
    }
    return c;
}
//