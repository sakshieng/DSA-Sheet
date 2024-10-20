// https://leetcode.com/problems/rank-transform-of-an-array/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        unordered_map<int,pair<int,int>>mp;
        //min heap
        priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int, int>>>minH;
        for (int i = 0; i < n; i++)
        {
            minH.push({arr[i],i});
        }
        int rank = 1;
        while(!minH.empty()){
            int val = minH.top().first;
            int idx = minH.top().second;
            if(mp.find(val) == mp.end())//not find
                mp[val] = {rank++,idx};
            ans[idx] = mp[val].first;
            minH.pop();
        }
        return ans;
    }
};

