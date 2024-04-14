//only diff from house robber 1 is last house is adjacent to 1st means it is circular list 2 chances are there leave first elmt and apply max sum of non adj or leave last apply max sum hence max of them is final ans
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:

int func(vector<int> &nums,int idx,vector<int>&dp){
    
    dp[0] = nums[0]; 
    for(int i=1;i<nums.size();++i){
        int pick = nums[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    return dp[nums.size()-1];
}

//TC->O(n) SC->O(n) no auxiliary stack space
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        vector<int>tmp1,tmp2;
        if(nums.size() == 1) return nums[0];
        for(int i=0;i<nums.size();++i){
            if(i != 0) tmp1.push_back(nums[i]);
            if(i != nums.size()-1) tmp2.push_back(nums[i]);
        }
        return max(func(tmp1,tmp1.size()-1,dp),func(tmp2,tmp2.size()-1,dp));
    }
};