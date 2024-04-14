
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/permutations/description/

class Solution {
public:

    void solve(vector<int>& curr,vector<int>& nums,vector<vector<int>> &ans,int freq[]){
        if(nums.size() == curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();++i){
                //if not in present in freq map
            if(!freq[i]){
                curr.push_back(nums[i]);
                freq[i]=1;
                solve(curr,nums,ans,freq);
                freq[i]=0;
                curr.pop_back();
            }
        } 
    }
   
    vector<vector<int>> permute(vector<int>& nums) {
    vector < vector < int >> ans;
      vector < int > curr;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      solve(curr, nums, ans, freq);
      return ans;
    }
};
/*
for permutation
1st box will decide where will I go _ _ _ _ in 4 pos
1 _ _ _ or _ 1 _ _ or _ _ _ 1 or _ _ 1 _
levels->boxes options->items
*/
