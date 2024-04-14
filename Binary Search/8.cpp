#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
      int mid;
      if(nums[mid]==target) return mid;
        if(nums.size()==0) return -1;
      while(hi-lo>1)
      {
        int mid=lo+(hi-lo)/2;
        if(nums[lo]<=nums[mid])
        {
        if(target<=nums[mid] && target>=nums[lo])  hi=mid-1;
        else lo=mid+1;
        }
        else
        {
          if(nums[mid]>=target && nums[hi]<=target)  lo=mid+1;
        else  hi=mid-1;
        }  
      }
      return -1;
      
    }
};
   return 0;
}