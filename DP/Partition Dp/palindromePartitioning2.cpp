/*find minimum partitions in order to make str palindrome
front partition
1.express everthing in terms of idx
2.express all possibilities
3.take min of all
4.base case
*/
/*find minimum partitions in order to make str palindrome
front partition
1.express everthing in terms of idx
2.express all possibilities
3.take min of all
4.base case
*/
#include <bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/palindrome-partitioning_873266?leftPanelTab=0
// https://leetcode.com/problems/palindrome-partitioning-ii/
using namespace std;

class Solution
{
public:
    bool isPalin(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return 0;
        }
        return 1;
    }
    int f(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0; // u reach end no partition required
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; ++j)
        {
            if (isPalin(s, i, j))
            {
                int cost = 1 + f(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        // the partiotion at the end should be subtracted means ABC 3 nhi 2 yayla hve
        return f(0, s.size(), s, dp) - 1;
    }
};