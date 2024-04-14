#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

void solve(vector<int>&arr){
    for (int i = 0; i < arr.size(); i++)
    {
        while(arr[i] != i+1){
            swap(arr[i],arr[arr[i]-1]);
        }
    }
}
int main()
{
   int n;cin>>n;
   vector<int>arr(n);
   for(auto &i:arr) 
    cin>>i;
    solve(arr);
    for(auto &i:arr)
        cout<<i<<" ";
   return 0;
}