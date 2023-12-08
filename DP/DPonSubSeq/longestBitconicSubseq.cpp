#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&leftPanelTab=0
using namespace std;

vector<vector<int>> dp1, dp2; 

int lis(vector<int>& nums, int n, int i) {
	// LIS , longest decreasing subseq are bitconic too
	//combine lis from front & back u will get bitonic 
    if (i == 0) return 1;
    if (dp1[i][i] != -1) return dp1[i][i];

    int maxLen = 1;
    for (int prev = 0; prev < i; ++prev) {
        if (nums[prev] < nums[i]) {
            maxLen = max(maxLen, 1 + lis(nums, n, prev));
        }
    }

    dp1[i][i] = maxLen; 
    return dp1[i][i]; 
}

int lds(vector<int>& nums, int n, int i) {
    if (i == n - 1) return 1;
    if (dp2[i][i] != -1) return dp2[i][i]; 

    int maxLen = 1;
    for (int prev = n - 1; prev > i; --prev) {
        if (nums[prev] < nums[i]) {
            maxLen = max(maxLen, 1 + lds(nums, n, prev));
        }
    }

    dp2[i][i] = maxLen; 
    return dp2[i][i]; 
}

int longestBitonicSubsequence(vector<int>& nums, int n) {
    dp1.assign(n, vector<int>(n, -1));
    dp2.assign(n, vector<int>(n, -1));

    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        maxi = max(maxi, lis(nums, n, i) + lds(nums, n, i) - 1);
    }

    return maxi;
}
