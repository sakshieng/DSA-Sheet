#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

// https://leetcode.com/problems/strange-printer/description/
class Solution {
public:
int solve(int i,int j,const string &s,vector<vector<int>>& dp){
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int minTurns = INT_MAX;
    for(int k=i;k < j;++k){
        //i to k left part and k+1 to j is right
        minTurns = min(minTurns,solve(i,k,s,dp)+solve(k+1,j,s,dp));
    }
    if(s[i] == s[j]){
            //means aba is there so a and a -1 from turns as 2 steps aaa mdhe b keley not 3 like for ab=2 and a=1
            return dp[i][j] = minTurns-1;
        }else{
            return dp[i][j] = minTurns;
    }
}
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(0,s.size()-1,s,dp);
    }
};
//TC->O(n^2*n) n^2 for dp and n for inside recursive calls SC->O(N^2)