#include <stdio.h>
#include<stdlib.h>
int main()
// pushing an element to array
{
   int arr1[100],i,n,p,inval;
   system("cls");
    printf("Input the size of array : ");
    scanf("%d", &n);
       printf("Input %d elements in the array in ascending order:\n",n);
       for(i=0;i<n;i++)
            {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }
   printf("Input the value to be inserted : ");
   scanf("%d",&inval);
   printf("The exist array list is :\n");
   for(i=0;i<n;i++)
      printf("% 5d",arr1[i]);
   for(i=0;i<n;i++)
   {	
    if(inval<arr1[i])
     {
       p = i;
       break;
     }
     else
     {
     	p=i+1;
      }
	 }
   for(i=n+1;i>=p;i--)
      arr1[i]= arr1[i-1];
      arr1[p]=inval;
      printf("\n\nAfter Insert the list is :\n");
   for(i=0;i<=n;i++)
      printf("% 5d",arr1[i]);
	  printf("\n");
}
