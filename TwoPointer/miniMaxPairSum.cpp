#include<bits/stdc++.h>
//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //O(nlog n) TC
        sort(begin(nums),end(nums));
        int i = 0,j = nums.size()-1;
        int ans = 0;
        while(i < j){
            int res = nums[i]+nums[j];
            ans = max(res,ans);
            i++;
            j--;
        }
        return ans;
    }
};