#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

// https://leetcode.com/problems/shortest-common-supersequence/
// length od SCS = n+m-len(LCS)
//on gfg we just have to return length so just use lcs func then n+m-len(lcs) return
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //TC->(N*M) SC->(N*M)
        int n = str1.size();
        int m= str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i <= n;++i){
            dp[i][0] = 0;
        }
        for(int j=0;j <= m;++j){
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }
        string ans = "";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};