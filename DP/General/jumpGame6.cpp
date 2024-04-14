#include <bits/stdc++.h>
// https://leetcode.com/problems/jump-game-vi/
using namespace std;
class Solution
{
public:
    int maximum(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind == 0 || ind == 1)
            return dp[ind] = nums[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int left = maximum(ind - 1, nums, dp) + nums[ind];

        int right = maximum(ind - 2, nums, dp) + nums[ind];
        return dp[ind] = max(left, right);
    }
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = max(maximum(n - 2, nums, dp), maximum(n - 1, nums, dp));
        return ans;
    }
};