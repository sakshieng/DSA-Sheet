/*
whenever u see a problem contains ...[i] + ...[j] == ...[j] + ...[i] rearrange it in such a way that i & j idx wale terms grouped
solved by using 
nums[i] -rev(nums[i])  == nums[j] -rev(nums[j]) 
nums = {13,10,35,24,76}
so nums would be {-18,9,-18,-18,9}
-18->3
9->1 in map this is stored
*/
// https://leetcode.com/problems/count-nice-pairs-in-an-array/?envType=daily-question&envId=2023-11-21
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m = 1e9+7;
    int rev(int num){
        int ans = 0;
        while(num>0){
            int rem = num % 10;
            ans = (ans*10) + rem;
            num = num/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i < n;++i)
            nums[i] = nums[i] - rev(nums[i]);
        int res = 0;
        for(int i=0;i<n;++i)
        {
            res = (res + mp[nums[i]])%m;
            mp[nums[i]]++;
        }
        return res;
    }
};