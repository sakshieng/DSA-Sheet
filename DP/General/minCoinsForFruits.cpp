#include<bits/stdc++.h>
//https://leetcode.com/contest/biweekly-contest-118/problems/minimum-number-of-coins-for-fruits/
using namespace std;

class Solution {
public:
    int solve(int ind, int n, vector<int> &prices, int take, vector<vector<int>> &dp)
    {
        if(ind == n)
            return 0;
        if(ind > n)
            return INT_MAX;
    
        if(dp[ind][take] != -1)
            return dp[ind][take];
        
        if(take)
        {
            return dp[ind][take] = min(prices[ind]+solve(ind+1, n, prices, ind+1, dp), solve(ind+1, n, prices, take-1, dp));
        }
        
        return dp[ind][take] = prices[ind] + solve(ind+1, n, prices, ind+1, dp);
    }
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return solve(0, n, prices, 0, dp);
    }
    
};