#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/palindromic-substrings/description/

class Solution
{
public:
    int countSubstrings(string s)
    {
        int cnt = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size() + 1, false));

        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (j - i == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1];
                    else
                        dp[i][j] = 0;
                }
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};