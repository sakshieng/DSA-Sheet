#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long ans = 0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) continue;
            int k = (nums[i]-1)/nums[i+1];
            ans += k;
            nums[i] /= (k+1);
        }
        return ans;
    }
};