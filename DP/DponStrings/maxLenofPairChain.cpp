#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-length-of-pair-chain/description/
//can be solved by greedy method also
using namespace std;

class Solution {
public:
//like LIS only
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = pairs.size();
        vector<int> dp(n, 1); 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxChainLength = 0;
        for (int i = 0; i < n; ++i) {
            maxChainLength = max(maxChainLength, dp[i]);
        }

        return maxChainLength;
    }
};
