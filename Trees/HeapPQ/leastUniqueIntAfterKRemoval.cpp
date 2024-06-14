#include<bits/stdc++.h>
//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        for (auto &&i : arr)
        {
            mp[i]++;
        }
        for (auto &&i : mp)
        {
            pq.push(i.second);
        }
        while (k > 0)
        {
            k -= pq.top();
            if(k >= 0) pq.pop();
        }
        return pq.size();
    }
};