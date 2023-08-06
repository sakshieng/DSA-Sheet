#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-break/description/
class Solution {
public:
//dp top-down
int dp[301];
    int help(int i,string s,set<string>& wordDict){
        if(i == s.size()) return 1;//able to segment
        string tmp;
        if(dp[i] != -1) return dp[i];
        for(int j=i;j<s.size();++j){
            tmp  += s[j];
            if(wordDict.find(tmp) != wordDict.end()){
                if(help(j+1,s,wordDict)) return dp[i] = 1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st;
        memset(dp,-1,sizeof dp);
       for(auto a:wordDict) st.insert(a);
       return help(0,s,st); 
    }
};
/*
// bottom up Dp
//bottom up
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto word : wordDict) {
            st.insert(word);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        // Empty string is always breakable
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        return dp[n] == 1;
    }
};
*/