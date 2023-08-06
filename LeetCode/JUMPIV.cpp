#include<bits/stdc++.h>
// https://leetcode.com/problems/jump-game-vi/
/* Sakshi */
using namespace std;

int main()
{
   class Solution {
public:
    int maxResult(int ind,int k,vector<int>& nums,vector<int> & dp) {
   if(ind==0 || ind==1)
     return dp[ind]=nums[ind];
      if (dp[ind] != -1)
        return dp[ind];
      int left = maxResult(ind - 1, nums, dp) + nums[ind];

      int right = maxResult(ind - 2,nums, dp) + nums[ind];
      return dp[ind] = max(left, right);
    }
  int maximum(vector<int> &nums,int k)
    {
      int n = nums.size();

      vector<int> dp(n + 1, -1);
      int ans = max(maxResult(n - 2, nums, dp), maxResult(n - 1, nums, dp));
      return ans;
    }
};
   return 0;
}