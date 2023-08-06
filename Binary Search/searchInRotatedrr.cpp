#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

class Solution{
    public :
        int search(vector<int> & nums, int target){
            int n = nums.size();
            int lo=0,hi=n-1,mid;
            while(lo < hi){
                mid = (hi-lo)/2;
                if(nums[mid] == target) return mid;
                else if(nums[lo] < nums[mid]){
                    if(target > nums[lo] && target < nums[mid]) hi = mid-1;
                    else lo = mid+1;
                }else {
                    if(target <= nums[hi] && target > nums[mid]) lo = mid+1;
                    else hi = mid-1;
                }
            }
            if(nums[lo] == target) return lo;
            if(nums[hi] == target) return hi;
            return -1;
        }
};