//i have 2 options i should go for free painter or for paid painter 
// https://leetcode.com/problems/painting-the-walls/description/?envType=daily-question&envId=2023-10-14
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int memo(vector<int>& cost, vector<int>& time,int i,int ans,vector<vector<int>>&dp){
        if(ans <= 0) return 0;
        if(i >= cost.size()) return 1e9;//out of bound
        if(dp[i][ans] != -1) return dp[i][ans];
        int pick = cost[i] + memo(cost,time,i+1,ans-(time[i]+1),dp);//paid
        int nonPick = memo(cost,time,i+1,ans-1,dp);//free
        return dp[i][ans] = min(nonPick,pick);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return memo(cost, time, 0, time.size(),dp);
    }
};