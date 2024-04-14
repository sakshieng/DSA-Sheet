#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    //for first occurance go as much as left side and for last occurance go right side
    int n=nums.size()-1;
    vector<int>ans;
    int lo=0,hi=n-1,mid;
    while(lo<=hi)
    {
        if(nums[mid]<=target)
        {
            //here equal to as just occurance ahet for BS we are returning for equal case
            // left side
            hi=mid-1;
            ans.push_back(mid);
        }
        else
        {
            lo=mid+1;
        }
        // else if(nums[mid]>=target)
        // {
        //     lo=mid+1;
        //     ans.push_back(mid);
        // }
        // else{
        //     hi=mid-1;
        // }
    }
    return ans;
    }
};
