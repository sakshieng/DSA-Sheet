#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
class Solution{
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       int l = 0,r = 0,cnt = 0,maxi = 0;
       while (r < nums.size())
       {
            if(nums[r] > right){
                maxi = 0;
                l = r+1;
            } else if(nums[r] >= left && nums[r] <= right){
                maxi = r-l+1;
            }
            cnt += maxi;//all subarrays add mhnje tevdhya window che sgle arr maxi zhale teh sarv cnt kra
            r++;
       }
       return cnt;
    }
};