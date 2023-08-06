#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
/*
Input: 
arr[] = {1, 2, 3, 4, 5, 6, 7}, d = 2
Output: 3 4 5 6 7 1 2

Input: arr[] = {3, 4, 5, 6, 7, 1, 2}, d=2
Output: 5 6 7 1 2 3 4

approach is to be by initializing temporoary variable 
int k is to keep a track of current index
*/
void rotate(int arr[],int d,int n)
{
    int tmp[n];
    int k=0;
    // Storing the n - d elements of
    // array arr[] to the front of temp[]
    for (int i = d; i < n; i++) {
        tmp[k] = arr[i];
        k++;
    }
 
    // Storing the first d elements of array arr[]
    //  into temp
    for (int i = 0; i < d; i++) {
        tmp[k] = arr[i];
        k++;
    }

    // Copying the elements of temp[] in arr[]
    // to get the final rotated array
    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
}
    
void printarray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
    cin>>arr[i];
   }
   int d;
   cin>>d;
   rotate(arr,d,n);
   printarray(arr,n);
   return 0;
}