//https://leetcode.com/problems/largest-divisible-subset/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        sort(nums.begin(), nums.end());
        int maxSize = 1, lastIndex = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < i; ++prev) {
                //for lis this line is nums[i]>nums[prev] as we have sorted we know i>prev hence direct modulo = 0 kela
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> lis(maxSize);
        int idx = maxSize - 1;
        while (lastIndex != -1) {
            lis[idx--] = nums[lastIndex];
            lastIndex = hash[lastIndex];
        }
        
        return lis;  
    }
};
