#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// we are shifting the element

/*
    for 10:
    10|  1   7   4   8   2   11
    for 1:
    1  10|   7   4   8   2   11
    for 7:
    1   7   10|   4    8   2   11
    for 4:
    1   4   7   10|    8   2   11
    for 8:
    1   4   7   8   10|     11
    for 11:
    1   4   7   8   10    11|
*/
void insertionSort(int n,vector<int>&arr)
{
    for(int i=0;i<n;i++)
    {
        int j;
        int temp=arr[i];
        for( j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                //shift
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int main()
{
    
    return 0;
}