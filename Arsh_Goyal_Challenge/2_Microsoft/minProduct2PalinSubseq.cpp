// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// disjoint palin
class Solution
{
public:
    vector<vector<int>> dp; // Define dp as a member variable

    int lcs(int i, int j, string &s1, string &s2)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);
        else
            return dp[i][j] = max({lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2), lcs(i - 1, j - 1, s1, s2)});
    }

    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string s2(s);
        reverse(s2.begin(), s2.end());
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return lcs(n - 1, n - 1, s, s2);
    }

    int maxProduct(string s)
    {
        int n = s.size(), N = (1 << n), res = 0;

        for (int mask = 1; mask < N; mask++)
        {
            string s1 = "", s2 = "";
            for (int j = 0; j < n; j++)
            {
                if ((mask >> j) & 1)
                    s1 += s[j];
                else
                    s2 += s[j];
            }
            res = max(res, longestPalindromeSubseq(s1) * longestPalindromeSubseq(s2));
        }
        return res;
    }
};