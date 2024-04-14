// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include<bits/stdc++.h>
using namespace std;

//keep the longest palindrome portion intact insertion we have to make len(str)-longest palind seq
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));  // Initialize all values in dp to 0
        
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return n-dp[0][n-1];
    }
};