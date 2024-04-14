// https://leetcode.com/problems/sort-characters-by-frequency/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i:s)
            mp[i]++;
        priority_queue<pair<int,char>>pq;
        
        for(auto &i:mp){
            pq.push({i.second,i.first});
        }
        string ans = "";
        pair<int,char>u;//{val,key} i.e. freqn & char
        while(!pq.empty()){
            u = pq.top();
            pq.pop();
            for(int i=0;i<u.first;++i)
                ans += u.second;
        }
        return ans;
    }
};
