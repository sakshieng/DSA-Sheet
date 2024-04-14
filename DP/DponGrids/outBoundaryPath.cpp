#include <bits/stdc++.h>
// https://leetcode.com/problems/out-of-boundary-paths/?envType=daily-question&envId=2024-01-26
using namespace std;



class Solution
{
public:
    int mod = 1e9 + 7;
    int memo(int m, int n, int i, int j, vector<vector<vector<int>>> &dp, int k)
    {
        if(i == -1 || i == m || j == -1 || j == n)
            return 1;
        if (k == 0)
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        int ans = 0;

        ans = (ans + memo(m, n, i + 1, j, dp, k - 1)) % mod;
        ans = (ans + memo(m, n, i - 1, j, dp, k - 1)) % mod;
        ans = (ans + memo(m, n, i, j + 1, dp, k - 1)) % mod;
        ans = (ans + memo(m, n, i, j - 1, dp, k - 1)) % mod;

        return dp[i][j][k] = ans; 
    }
    int findPaths(int m, int n, int k, int i, int j)
    {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k + 1,-1)));
        return memo(m,n,i,j,dp,k);
    }
};