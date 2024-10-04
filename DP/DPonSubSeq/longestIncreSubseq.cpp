#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos
//check binary search approach
// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
vector<vector<int>>dp;
    int memo(vector<int>&nums,int curr,int prev)
    {
        if(curr>=nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int pick=0;
        if( prev == -1 || nums[curr] > nums[prev]){
            pick = 1+memo(nums,curr+1,curr);
        }  
        int nonPick=0+memo(nums,curr+1,prev);
        return dp[curr][prev+1] = max(pick,nonPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return memo(nums,0,-1);
    }
};
/*
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;++i){
            for(int prev=0;prev<i;++prev){
                if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] > maxi) 
                maxi = dp[i];
        }
        return maxi;
    }
};

*/
/*
//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
int longestSubsequence(int n, int a[])
    {
       vector<int>ans;
       ans.push_back(a[0]);
       int len=1;
       for(int i=1; i<n; i++){
           if(a[i]>ans.back()){
               ans.push_back(a[i]);
               len++;
           }
           else{
               int ind=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
               ans[ind]=a[i];
           }
       }
       return len;
    }
*/
