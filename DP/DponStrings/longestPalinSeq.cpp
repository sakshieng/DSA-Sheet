#include <iostream>
#include <cstring>
// https://leetcode.com/problems/longest-palindromic-subsequence/
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Get the length of the input string
        int n = s.length();
        // Initialize a 2D array to store the length of the longest palindromic subsequence
        int dp[n][n];
        memset(dp, 0, sizeof(dp));  // Initialize all values in dp to 0
        
        // Iterate over the substrings in reverse order to fill in the dp table bottom-up
        for (int i = n-1; i >= 0; i--) {
            // Base case: the longest palindromic subsequence of a single character is 1
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                // If the two characters match, the longest palindromic subsequence can be extended by two
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    // Otherwise, we take the maximum of the two possible substrings
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        // The length of the longest palindromic subsequence is in the top-right corner of the dp table
        return dp[0][n-1];
    }
};
