#include<bits/stdc++.h>
//https://leetcode.com/problems/top-k-frequent-words/description/
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        priority_queue<pair<int, string>> max_heap; // max heap

        for (auto &word : words) {
            cnt[word]++;
        }

        for (auto &entry : cnt) {
            max_heap.push({-entry.second, entry.first});
            if(max_heap.size() > k) max_heap.pop();
        } 

        vector<string> ans;
        while (k--) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
