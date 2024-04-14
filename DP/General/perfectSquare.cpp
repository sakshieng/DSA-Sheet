#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//space optimize check dp ki dependancy dp[i]->dp[i-j*j]
    int solveTab(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i <= n;++i){
            for(int j=1;j*j <= n;++j){
                int temp = j*j;
                if(i-temp >= 0)
                    dp[i] = min(dp[i],1 + dp[i-temp]);
            }
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        return solveTab(n);
    }
};
/*
dp[5]->dp[5-1^2]= dp[4]
    ->dp[5-2^2]=dp[1]
no pattern is there hence no space optimize
*/