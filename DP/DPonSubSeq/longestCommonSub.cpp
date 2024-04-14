#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
//https://leetcode.com/problems/longest-common-subsequence/solutions/
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution {
public:
//space optimization
    int solveTabulation(string a,string b){
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);
        int ans = 0;
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
            if(a[i] == b[j]) ans = 1+next[j+1];
            else ans = max(next[j],curr[j+1]);
            curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTabulation(text1,text2);
    }
};