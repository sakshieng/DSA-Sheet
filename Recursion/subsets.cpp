// https://leetcode.com/problems/subsets/description/
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

class Solution {
public:
//we have to return the power set 
    void solve(int idx,vector<int>& curr,vector<vector<int>> &ans,vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        //ith element not in subset
        solve(idx+1,curr,ans,nums);
        //add ith element
        curr.push_back(nums[idx]);
        solve(idx+1,curr,ans,nums);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(0,curr,ans,nums);
        return ans;
    }
};
/*
[1 2 3] -> curr 
*/