//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
  int sum(int arr[], int n)
{
    int sum = 0; 
    for (int i = 0; i < n; i++)
    sum += arr[i];
    return sum;
}
int largest(int arr[], int n)
{
    return *max_element(arr, arr+n);
}
 
int main()
{
long long t; 
cin>>t;
while(t--)

    {
        
       int n;
        cin>>n;
         int arr[n];
       int i;
        for ( i = 0; i < 0; i++)
        {
            cin>>arr[i];
        }
        int k=abs(sum(arr,n)-largest(arr,n));
        cout<<max(k,largest(arr,n))<<endl;
    }
    return 0;
}