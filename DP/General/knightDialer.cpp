#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/knight-dialer/editorial/?envType=daily-question&envId=2023-11-27
//trying all possibilities -> dp
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>>possibleJumps = {
        {4,6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };//empty bracket is for 5
    int memo(int i,int j,vector<vector<int>>&dp)
    {
        if(i == 0)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for(auto nextSquare:possibleJumps[j])
            ans = (ans + memo(i-1,nextSquare,dp))%mod;
        return dp[i][j] = ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(10, -1));
        int ans = 0;
        for (int square = 0; square < 10; square++)
        {
            ans = (ans + memo(n-1,square,dp))%mod;
        }
        return ans;
    }
};