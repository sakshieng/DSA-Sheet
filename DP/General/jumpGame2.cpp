#include<bits/stdc++.h>
//u can definately jump tell how many jumps u will need to do it
using namespace std;
// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int memoization(vector<int>&nums,int idx,int jumps,vector<int>&dp){
        if(idx >= nums.size()-1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int mini = INT_MAX-1;
        for (int i = 1; i <= nums[idx]; i++)
        {
            mini = min(mini,1+memoization(nums,idx+i,jumps+1,dp));
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        // if(nums[0] == 0 && nums.size()==1) return 0;
        vector<int>dp(nums.size()+1,-1);
        return memoization(nums,0,0,dp);
    }
};