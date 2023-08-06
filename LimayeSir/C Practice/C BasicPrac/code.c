#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,flag=0;
    system("cls");
    printf("\nEnter a number:");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
        else 
        flag=0;
    }
  if(flag) //flag is always zero 
  {
      printf("%d is not a prime number\n",n);
  }
  else
  {
      printf("%d is a prime number\n",n);
  }
return 0;  
}