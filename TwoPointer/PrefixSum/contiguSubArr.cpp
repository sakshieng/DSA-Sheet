#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16

class Solution {
public:
//prefix sum
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0] = -1;
        //if prefix sum at 2 idx is same it means no of 1 and 0 betn those 2 idxes is same
        int sum = 0;
        int subArrLen = 0;//max subarr len
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0){
                sum += -1;
            }else{
                sum += 1;
            }
            if(mp.find(sum) != mp.end()){
                subArrLen = max(subArrLen,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return subArrLen;
    }
    //another submission
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int>mp;
       int sum = 0;
       int lonegstSubarr = 0;
       for (int i = 0; i < nums.size(); i++)
       {
            sum += (nums[i] == 0) ? -1 : 1;
            if(sum == 0)
            {
                if(lonegstSubarr < i+1)
                    lonegstSubarr = i+1;
            }else if(mp.find(sum) != mp.end())
            {
                if(lonegstSubarr < (i-mp[sum]))
                    lonegstSubarr = (i-mp[sum]);
            }else mp[sum] = i;
       }
        return lonegstSubarr;
    }
     
    
};

