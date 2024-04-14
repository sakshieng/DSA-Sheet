#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
/*
Triangle of Mahonian Numbers
we have n elmts in permutation then where we put (n+1) in our permutation will decide new inverse pairs
5 x x x x creates 4 new inverse pairs
x 5 x x x creates 3 new inverse pairs
x x 5 x x creates 2 new inverse pairs
dp[n][k] = dp[n-1][k-0]+dp[n-1][k-1]+dp[n-1][k-2]+.....+dp[n-1][k-(n-1)]
*/
    const int mod = 1e9 + 7;
    int dp[1001][1001];
    int memo(int n,int k){
        if(k <= 0)
            return k == 0;
        if(dp[n][k] != -1)
            return dp[n][k];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += memo(n-1,k-i);
            ans %= mod;
        }
        return dp[n][k] = ans;        
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return memo(n,k);
    }
};