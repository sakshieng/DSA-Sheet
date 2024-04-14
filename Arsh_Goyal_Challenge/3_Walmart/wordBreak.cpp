//https://leetcode.com/problems/word-break/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


class Solution {
public:
unordered_map<string,bool>dp;//as data type for dp are fdiffrent use map
bool solve(string s,unordered_set<string>&mp){
    if(s.length() == 0)
        return 1;
    if(dp.find(s) != dp.end())
        return dp[s];
    for (int i = 0; i < s.length(); i++)
    {
        string r = s.substr(0,i+1);
        if(mp.count(r))
        {
            if(solve(s.substr(i+1),mp))
                return dp[s] = 1;
        }
    }
    return dp[s] = 0;
}//n^3 log n
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp;
        for(auto &x:wordDict)
            mp.insert(x);
        return solve(s,mp);
    }
};