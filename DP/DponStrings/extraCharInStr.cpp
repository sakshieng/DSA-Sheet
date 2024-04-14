
#include<bits/stdc++.h>
//https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02
using namespace std;

class Solution {
public:
vector<int>dp;
int memo(int i,string &s,map<string,int>&lis){
    if(i >= s.size()) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    string str = "";
    for(int j=i;j < s.size();++j){
        str += s[j];
        if(lis[str]) ans = min(ans,memo(j+1,s,lis));
    }
    ans = min(ans,1+memo(i+1,s,lis));
    return dp[i] = ans;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.size()+1,-1);
        map<string,int>lis;
        for(auto s:dictionary) lis[s]++;
        return memo(0,s,lis);
    }
};