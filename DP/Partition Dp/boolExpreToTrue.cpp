//at operand we are doing different partitions 
#include <bits/stdc++.h>
using namespace std;
    
// https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

const int mod = 1e9 + 7;
#define ll long long

int f(int i, int j, int isTrue, string &exp,vector<vector<vector<ll>>>&dp) {
    if (i > j)
        return 0;
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    if (i == j) {
        if (isTrue == 1)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    ll ways = 0;
    for (int idx = i + 1; idx <= j - 1; idx += 2) {
        ll lT = f(i, idx - 1, 1, exp,dp);
        ll lF = f(i, idx - 1, 0, exp,dp);
        ll rT = f(idx + 1, j, 1, exp,dp);
        ll rF = f(idx + 1, j, 0, exp,dp);

        if (exp[idx] == '&') {
            if (isTrue)
                ways = (ways + (rT * lT) % mod) % mod;
            else
                ways = (ways + ((lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod) % mod;
        } else if (exp[idx] == '|') {
            if (isTrue)
                ways = (ways + ((rT * lT) % mod + (rF * lT) % mod + (rT * lF) % mod) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod) % mod;
        } else {
            if (isTrue)
                ways = (ways + ((rT * lF) % mod + (rF * lT) % mod) % mod) % mod;
            else
                ways = (ways + ((rF * lF) % mod + (rT * lT) % mod) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0, n - 1, 1, exp,dp);
}


