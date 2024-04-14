#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/permutations/description/

class Solution {
public:
//backtracking
void solve(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(index + 1, nums, ans);
        //backtrack
        swap(nums[index], nums[i]);
      }
    }
  
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      solve(0, nums, ans);
      return ans;
    }
};
