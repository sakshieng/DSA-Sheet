#include <bits/stdc++.h>
// maximum frequency
using namespace std;

class Solution
{
public:  
  int MaxFrequency(int N, vector<int> &arr, int K, int X)
  {
    // take idx i & replace arr[i] with integer from range [arr[i]-X,arr[i]+X]
    vector<int> all;
    unordered_map<int, int> mp;
    for (auto it : arr)
    {
      mp[it]++;
      all.push_back(it);
      all.push_back(it + X);
    }
    sort(arr.begin(), arr.end());
    int maxi = 1;
    for (auto it : all)
    {
      int ub = upper_bound(arr.begin(), arr.end(), it + X) - arr.begin();
      int lb = lower_bound(arr.begin(), arr.end(), it - X) - arr.begin();
      int op = ub - lb - mp[it];
      maxi = max(maxi, min(K, op) + mp[it]);
    }
    return maxi;
  }
};