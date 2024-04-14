#include<bits/stdc++.h>
//https://leetcode.com/problems/top-k-frequent-words/
using namespace std;


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;    
        for(auto &i:words)
            mp[i]++;
        priority_queue<pair<int,string>>pq;
        for (auto &i:mp)
        {
            pq.push({-i.second,i.first});
            if(pq.size() > k)
                pq.pop();
        }
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};