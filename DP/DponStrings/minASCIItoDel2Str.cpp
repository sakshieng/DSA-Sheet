#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &a,string &b,int i,int j){
        if(i == a.length() && j == b.length()) return dp[i][j]=0;//both str are same
        if(a.length() == i) return dp[i][j] = b[j]+solve(a,b,i,j+1);
        if(b.length() == j) return dp[i][j] = a[i]+solve(a,b,i+1,j);
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]) ans = solve(a,b,i+1,j+1);
        else ans = min(solve(a,b,i+1,j)+a[i],solve(a,b,i,j+1)+b[j]);
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,0,0);
    }
};
/*
minDeleteSum = ascii(s1)-ascii(s2)-2*ascii(LCS)
s1+s2-2*LCS
TC=SC=O(n1⋅n2)
sea eat LCS ea so ascii(sea)+ascii(eat)-2*ascii(ea)=ascii(s,t)
*/