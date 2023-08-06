#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/delete-operation-for-two-strings/description/
    
class Solution {
public:
    vector<vector<int>>dp;
    int minDistance(string& word1, string& word2) {
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 1000));
        return helper(word1, word2, 0, 0);
    }
    int helper(string &w1, string &w2, int i, int j) {
        if(i == w1.size() && j == w2.size()) return 0;//means same str
        if(i == w1.size() || j == w2.size()) return max(w1.size() - i, w1.size() - j);//if one of the string is empty we will return char from str which is nonempty
        if(dp[i][j] != 1000) return dp[i][j];  
        if(w1[i] == w2[j]) return helper(w1, w2, i + 1, j + 1);
        return dp[i][j] = 1 + min(helper(w1, w2, i + 1, j), helper(w1, w2, i, j + 1));
    }
};