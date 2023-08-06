#include <stdio.h>
int main()
//check inputed no is prime by conditional if...else
{
    int n,i,flag=0;
    printf("\nEnter a number:");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n==2)
        {
            break;
        }
        else
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
  if(flag)  
  {
      printf("%d is not a prime number\n",n);
  }
  else
  {
      printf("%d is a prime number\n",n);
  }
return 0;  
}