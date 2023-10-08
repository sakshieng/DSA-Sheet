#include<bits/stdc++.h>
// https://leetcode.com/problems/longest-string-chain/?envType=daily-question&envId=2023-09-23
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& w) {
        //dp
        sort(w.begin(),w.end(),[](const string &s1,const string &s2){
            return s1.size()<s2.size();
        });
        unordered_map<string,int>dp;
        int maxi = 0;
        for(const string &i:w){
            dp[i] = 1;
            for(int it=0;it<i.size();++it){
                string prev = i.substr(0,it) + i.substr(it+1);
                if(dp.find(prev) != dp.end()){
                    dp[i] = max(dp[i],dp[prev]+1);//we are taking prev so add 1
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};