// https://leetcode.com/problems/rank-transform-of-an-array/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<int>tmp = arr;
        sort(begin(tmp),end(tmp));
        int currRank = 1;
        vector<int>rank(arr.size());
        rank[0] = currRank;
        //giving ranks in sorted array
        for(int i=1;i<tmp.size();++i){
            if(tmp[i] != tmp[i-1]){
                currRank++;    
            } 
            rank[i] = currRank;
        }
        //asigning it to original arr
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();++i){
            auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);//find idx of elmt in sorted arr
            ans[i] = rank[it-tmp.begin()];
        }
        return ans;
    }
};