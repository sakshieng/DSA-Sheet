//abs diff is same as max(a, b) - min(a, b)
//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        // int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int>ans(n);
        vector<int>prefixSum(n),suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            //rather than reverse loop for suffix sum we are doing it in one loop
            suffixSum[n-i-1] = suffixSum[n-i] + nums[n-i-1];
        }
        //abs diff
        for (int i = 0; i < n; i++)
        {
            int diff = ((nums[i]*i) - prefixSum[i]) + (suffixSum[i] - (nums[i]*(n-i-1)));
        }
        return ans;
    }
};