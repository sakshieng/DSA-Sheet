// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//Variable Sliding Window
    int maxSubarrayLength(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int>mp;
       int i = 0,j = 0;
       int ans = 0;
       while (i<n and j<n)
       {
        mp[nums[j]]++;
        while (mp[nums[j]] > k)
        {
            mp[nums[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
       }
       return ans;
        
    }
};