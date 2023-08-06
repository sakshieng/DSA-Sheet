/*
Selection sorting ::
First element ani baki array til min element swap parat second ani baki array til min element swap upto i=n-1

|3 1 5 6 4
min :: 1
1 | 3 5 6 4
min :: 3
1 3 | 6 5 4
min :: 4
1 3 4 | 5 6
min :: 5
1 3 4 5 | 6
min :: 6
1 2 3 4 5 6 |
Space complexity :: O(1)
// as we have only created variables like i,j,minIndex no extra space :: O(1)
Time complexity  :: O(n²)
*/
#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

void selectionSort(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int miniIndex=i;
        for ( int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[miniIndex])
            {
                miniIndex=j;
            }
        }
        swap(arr[miniIndex],arr[i]);   
    } 
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
    selectionSort(a,n);
    print_array(a,n);
    return 0;
}

