#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution {
public:
//memo
int solve(vector<int>& nums,int i,vector<int>& dp){
    int n = nums.size();
    //partition is compltete 1 return
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    bool res = false;
    if(i+1<n && nums[i]==nums[i+1]){
    //i and i+1 he ek valid so move to i+2
        res = solve(nums,i+2,dp);

    //i+2 valid so move to i+3
        if(i+2<n && nums[i]==nums[i+2])
            res = res || solve(nums,i+3,dp);
    }
    //check adjacent/not 2nd 1st diff=1 and 3rd 2nd diff=1 
    if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
        //this partition is of len 3
        res = res || solve(nums,i+3,dp);
    }
    return dp[i] = res;
}
    bool validPartition(vector<int>& nums) {
        int n =nums.size();
        if(n == 2) return nums[0] == nums[1];
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};