#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
void bubbleSort(int arr[],int n)
{
   for (int i = 0; i < n-1; i++)
   {
    bool swapped=false;
      for (int j = 0; j < n-1; j++)
      {
        //  proceed element till (n-1)^th index
         if(arr[j]>arr[j+1])
         {
            swap(arr[j],arr[j+1]);
            swapped=true;
         }
      }
      if(swapped=false)
      // already sorted
      break;
   }
  //TC--> O(n)-->Best case    SC-->O(1)
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

