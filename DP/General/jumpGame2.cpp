#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    vector<int>dp;
    int memo(vector<int>& nums,int idx){
        if(idx >= nums.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int miniJumps = INT_MAX - 1;
        for(int i=1;i <= nums[idx];++i){
            miniJumps = min(miniJumps,1+memo(nums,idx+i));
        }
        return dp[idx] = miniJumps;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size() + 2, -1);
        return memo(nums,0);
    }
};