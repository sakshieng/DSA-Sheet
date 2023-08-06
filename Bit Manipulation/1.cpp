#include <bits/stdc++.h>
using namespace std;
//even last bit 0 and odd last bit 1 1110 divide by 2 means remove 0 means right shift 2
void countFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    for (auto x : mp)
        cout << x.first << " " << x.second << endl;
}
  
int main()
{
    int t;
    cin>>t;
    while(t--);
    {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
    }
}