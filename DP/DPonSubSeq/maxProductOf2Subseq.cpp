#include<bits/stdc++.h>
//https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2023-10-08
using namespace std;

//type of LCS
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return INT_MIN;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int takeBoth = nums1[i] * nums2[j] + max(0, memo(nums1, nums2, i - 1, j - 1, dp));
        int skipNums1 = memo(nums1, nums2, i - 1, j, dp);
        int skipNums2 = memo(nums1, nums2, i, j - 1, dp);
        
        return dp[i][j] = max({takeBoth, skipNums1, skipNums2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int result = memo(nums1, nums2, n - 1, m - 1, dp);
        
        return result;
    }
};