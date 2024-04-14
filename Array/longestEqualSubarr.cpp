// https://leetcode.com/problems/find-the-longest-equal-subarray/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int>mp;
        int maxi=0,j=0,ans=0;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
            maxi = max(maxi,mp[nums[i]]);
            ans = max(ans,maxi);
            sum++;
            while(sum-maxi > k){
                mp[nums[j]]--;
                sum--;
                maxi = max(maxi,mp[nums[j]]);
                j++;
            }
        }
        return ans;
    }
};
