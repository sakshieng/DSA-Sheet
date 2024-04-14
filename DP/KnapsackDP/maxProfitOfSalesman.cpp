#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/
// knapsack dp + binary search
class Solution {
public:
//1 state 1-d dp
    int solve(vector<vector<int>>& offers,int i,vector<int>& dp){
        if(i == offers.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int nonPick = solve(offers,i+1,dp);
        int n = offers.size();
        int low = i+1,high = n-1;
        while (low <= high)
        {
            int mid = low + (high-low)/2;
            if(offers[mid][0] > offers[i][1])
            {
                high = mid-1;
                n = mid;
            }else{
                low = mid+1;
            }
        }
        int pick = offers[i][2] + solve(offers,n,dp);
        return dp[i] = max(pick,nonPick);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
//pick nonPick approach
        int m=offers.size();
        vector<int>dp(m,-1);
        return solve(offers,0,dp);
    }
};
