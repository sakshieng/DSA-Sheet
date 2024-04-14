#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        //case of 7 there are 5 ways means 1 5 4 3 2 can be added one by one to 6 7 to form LIS
        vector<int>dp(n,1),cnt(n,1);
        int maxi = 1;
        for(int i=0;i<n;++i){
            for(int prev=0;prev<i;++prev){
                if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    //inherit no add
                    cnt[i] = cnt[prev];
                }
                else{
                    //another LIS with same value so add it 
                    if(nums[prev] < nums[i] && 1+dp[prev] == dp[i]){
                        cnt[i] += cnt[prev];
                    }
                }
                maxi = max(maxi,dp[i]);
            }            
        }
        int number = 0;
        for(int i=0;i<n;++i){
            if(dp[i] == maxi) number += cnt[i];//all LIS added
        } 
        return number;
    }
};
/*
        1 5 4 3 2 6 7 
dp[]    1 2 2 2 2 2 3 
cnt[]   1 1 1 1 1 5 9 
there are 5 LIS of length 2 ends at idx 6
there are 9 LIS of length 3 means 5 will get attached to 7 which is already having LIS of 2 so total length would be 3

when there is LIS at dp[] means here LIS is 3 so cnt add kra jya idx la 3 ahe
*/