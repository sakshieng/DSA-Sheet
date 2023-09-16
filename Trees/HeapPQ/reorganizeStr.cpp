#include<bits/stdc++.h>
// https://leetcode.com/problems/reorganize-string/description/
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        // we have to give priority to max freqn char
        //tc O(nlogk) k is no. of unique char in str sc O(n)
        map<int, int> mp;
        for(auto &i:s) mp[i]++;
        priority_queue<pair<int, char>> pq;//max heap
        for(auto &i:mp){
            pq.push({i.second,i.first});
        }
        //[(-2, 'a'), (-1, 'b')] first second elemt in heap after initial
        string res;
        while(pq.size() >= 2){
            auto c1 = pq.top();
            pq.pop();
            auto c2 = pq.top();
            pq.pop();
            res += c1.second;
            res += c2.second;
            if(c1.first-1 > 0) pq.push({c1.first-1,c1.second});
            if(c2.first-1 > 0) pq.push({c2.first-1,c2.second});
        }
        if(pq.size() != 0) {
            if(pq.top().first > 1) return "";
            res += pq.top().second;
        }
        return res;
    }
};
/*
get first two char from heap append to res decre their freq and re-insert them back to heap
if there is still remaining car with freq 1 append it to res
*/