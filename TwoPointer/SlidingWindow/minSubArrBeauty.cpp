//take subarray of len k & return xth smallest num from it
#include<bits/stdc++.h>
//https://leetcode.com/problems/sliding-subarray-beauty/
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        //we need to use ordered map to have it in sorted fashion
        //range i s-50 to 50 find x in -1 to -50
          vector<int>ans;
    int n = nums.size();
    map<int,int>mp;
    int j  = 0;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if(i-j+1 > k){//remove it from window
            mp[nums[j]]--;
            j++;
        }
        if(i-j+1 == k){
            //we are adding freq
            int cnt = 0;
            for (auto &&idx : mp)
            {
                cnt += idx.second;
                if(cnt >= x){
                   if(idx.first < 0) ans.push_back(idx.first);
                   else ans.push_back(0);
                   break;//ow is keep adding 0 until the codn is satisfied
                }
            }
            
        }
    }
        return ans;
    }
};