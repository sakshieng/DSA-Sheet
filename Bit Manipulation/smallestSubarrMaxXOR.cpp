#include<bits/stdc++.h>
//https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/ 
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        //check the min idx from curr idx that is reponsible for set ith bit and update it from right to left
        vector<int>mp(31,-1);
        vector<int>ans;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<31;j++){
                int mask = (1<<j);
                if((mask & nums[i]))//check jth bit is set or not
                {
                    //if jth bit set update this to cur idx means jth bit can be set by this idx
                    mp[j] = i;
                }
            }
            int res = -1;
            for(auto x:mp){
                res = max(res,x);//find the max idx which are contributing to max xor
            }
            if(res != -1) ans.push_back(res-i+1);
            else ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};