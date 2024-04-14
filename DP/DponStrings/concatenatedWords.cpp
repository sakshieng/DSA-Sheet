#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/ninja-and-the-words_3189109?count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTab=0
//https://leetcode.com/problems/concatenated-words/description/
using namespace std;

class Solution {
public:
    int solve(string &s,int idx,int part,int n,unordered_map<string,int>&mp){
        if(idx >= n)
            return part;
        string tmp = "";
        for(int i = idx;i<n;++i){
            tmp += s[i];
            if(mp.find(tmp) != mp.end()){
                int ans = solve(s,i+1,part+1,n,mp);
                if(ans >= 2)
                    return ans;
            }
        }
        return -1;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        int size = words.size();
        unordered_map<string,int> mp;
        for(auto word:words)
            mp[word]++;
        for (int i = 0; i < size; i++)
        {
            int n = words[i].size();
            if(solve(words[i],0,0,n,mp) >= 2)
                res.push_back(words[i]);
        }
        return res;
    }
};