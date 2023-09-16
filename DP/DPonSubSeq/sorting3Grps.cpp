// https://leetcode.com/problems/sorting-three-groups/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>>dp;
    int memo(vector<int>&nums,int curr,int prev)
    {
        if(curr>=nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int pick=0;
        if( prev == -1 || nums[curr] == nums[prev] || nums[curr] > nums[prev]){//equal as 223344 is valid not just 234
            pick = 1+memo(nums,curr+1,curr);
        }  
        int nonPick=0+memo(nums,curr+1,prev);
        return dp[curr][prev+1] = max(pick,nonPick);
    }
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return n-memo(nums,0,-1);
    }
};
// we want 111222233333 he hava ahe in que we have 132223311 
// 123 je order madhe ahet te nhi change kryche baaki kryche ahet Order madhe kon ahe LIS ( because increase ) so return n-lis
