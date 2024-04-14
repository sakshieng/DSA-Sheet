// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    /*
    dp[i][j] -> length of longest common subarray till len i of 1st arr & j of 2nd arr
    nums1= 1 2 3 2 1
    i ithe kiti ghyche elmts teh tharvel
    nums2=3 2 1 4 7
    ithe j
    if(nums[i]==nums[j]){
        dp[i][j] = 1 + dp[i-1][j-1]
    }
    */
    
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>>dp;
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        dp.resize(n+1,vector<int>(m+1,0));//as we are doing tabulation
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if (nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = max(dp[i-1][j-1]+ 1, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
                ans = max(dp[i][j],ans);
            }
        }
        return ans;
    }
};