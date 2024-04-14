#include<bits/stdc++.h>
//https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
using namespace std;

class Solution {
public:
//using map
//tc O(N) sc O(N)
//map store sorted order
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        // for (auto &[key,val]:mp)
        // {
        //     if(mp.find(key+k)!=mp.end())
        //         cnt++;
        //     else {
        //         if(mp[key] > 1)//occurs 2 times
        //             cnt++;
        //     }
        // }
        return cnt;
    }
};