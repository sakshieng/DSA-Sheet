#include<bits/stdc++.h>
//quick,merge and sort are comparison based algorithms
using namespace std;
// in i^th round i^th largest element will reach at right place
void bubbleSort(int arr[],int n)
{
   for (int i = 0; i < n-1; i++)
   {
      for (int j = 0; j < n-1; j++)
      //  for (int j = 0; j < n-1-i; j++)
      {
         // as when 1 6 7 9 10 14 when j is at 10 it will compare with j+1^th element i.e. with 14 ::loop upto n-1

         /*
                1     6    7    9    10   14
      round:                        n-1   n-2
      value:j=0                      j    j+1      
         */
         if(arr[j]>arr[j+1])
         {
            swap(arr[j],arr[j+1]);
         }
      }
      
   }
   // TC-->O(n^2) SC-->O(1)
   
}
void print_array(int arr[],int size)
{
   for (int i = 0; i < size; i++)
   {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i = 0; i < n; i++)
   {
      cin>>a[i];
   }
   bubbleSort(a,n);
   print_array(a,n);
   return 0;
}

