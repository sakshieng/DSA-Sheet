// https://leetcode.com/problems/burst-balloons/description/

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
//MCM
class Solution {
public:
//its like a chain in which we are bursting the ballons
    int solve(vector<int>&a,int i,int j,vector<vector<int>>&dp){
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int maxi = INT_MIN;
        for(int idx = i;idx <= j;++idx){
            int cost = a[i-1]*a[idx]*a[j+1] + solve(a,i,idx-1,dp) + solve(a,idx+1,j,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        //so for 1st and last ballon of array we are multiplying it with 1
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return solve(nums,1,nums.size()-2,dp);// since nums now has an additional first and last element.
    }
};