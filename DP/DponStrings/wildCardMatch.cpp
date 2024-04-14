#include <bits/stdc++.h>
using namespace std;
// tabulation
// https://leetcode.com/problems/wildcard-matching/
// https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
bool wildcardMatching(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
 

    for (int i = 1; i <= n; ++i)
    {
        bool flg = true;
        for (int it = 1; it <= i; ++it)
        {
            if (s[it - 1] != '*')
            {
                flg = false;
                break;
            }
        }
        dp[i][0] = flg;
    }
    //   changing parameters
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (s[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}
/*
for the base case
s1 exhausted then s2 has to be exhausted if not then return false
but 
if s2 exhausted and s1 remain then it must have only * left
as * can match with null

Recursion TC->exponential SC->auxiliary space O(n+m)
if there are overlapping subsequences
then use  
memoization TC->O(n*m) SC->O(n*m)+O(n+m)
*/