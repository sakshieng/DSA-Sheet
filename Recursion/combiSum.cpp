// https://leetcode.com/problems/combination-sum/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//backtrack func
    void solve(vector<int>& c, int k,vector<vector<int>>&ans,int idx,vector<int>&curr){ 
        if(k == 0){
            ans.push_back(curr);
            return;
        }
        if(k < 0) return;
        for(int i=idx;i < c.size();++i){
            curr.push_back(c[i]);
            solve(c,k-c[i],ans,i,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(candidates,k,ans,0,curr);
        return ans;

    }
};
