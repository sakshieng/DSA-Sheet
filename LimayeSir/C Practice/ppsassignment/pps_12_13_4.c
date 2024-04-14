 // 4) Write a program in C to get the largest element of an array using the function.
#include<stdio.h>
#include<stdlib.h>
 int findMaxElem(int []);
 int Max;
 int n;
 int main()
 {
     int arr1[Max],mxelem,i;
     system("cls");
     printf("enter the size of array :");
     scanf("%d",&n);
     printf(" enter  %d elements in the array :\n",n);
     for(i=0;i<n;i++)
     {
 	      printf(" element - %d : ",i);
 	      scanf("%d",&arr1[i]);
 	   }
     mxelem=findMaxElem(arr1);
     printf(" The largest element in the array is : %d\n\n",mxelem);
     return 0;
 }
 int findMaxElem(int arr1[])
 {
     int i=1,mxelem;
     mxelem=arr1[0];
     while(i < n)
  	{
       if(mxelem<arr1[i])
        mxelem=arr1[i];
       i++;
    }
     return mxelem;
 }