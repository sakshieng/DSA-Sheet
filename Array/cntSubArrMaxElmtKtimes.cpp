//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
#include<bits/stdc++.h>
//lc 375 3rd contest question
using namespace std;

class Solution {
public:
//sliding window
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int>A = nums;
        int maxi = INT_MIN,n = nums.size(),curr = 0,left = 0;
        for(int i=0;i<n;++i)       
            maxi = max(maxi,nums[i]);
        long long res = 0;
        for (int right = 0; right < n; right++)
        {
            if(A[right] == maxi)
                curr++;
            while (curr >= k)
            {
                if(A[left] == maxi)
                    curr--;
                left++;    
            }
            res += left;
        }
        return (long long)res;
    }
};