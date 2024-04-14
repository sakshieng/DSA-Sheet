//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
const int mod = 1e9 + 7;
class Solution {
public:
    vector<vector<int>>dp;
    int solve(int diceIdx,int remTarget,int n,int k){
        if(diceIdx == n) return remTarget == 0;
        if(remTarget < 0) return 0;
        if(dp[diceIdx][remTarget] != -1)
            return dp[diceIdx][remTarget];
        int ans = 0;
        for(int face = 1;face <= k;++face){
            ans = (ans + (solve(diceIdx+1,remTarget-face,n,k)%mod))%mod;
        }
        return dp[diceIdx][remTarget] = (ans%mod);
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(0,target,n,k);
    }
};