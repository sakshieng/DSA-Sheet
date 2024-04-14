#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/wildcard-matching/description/
//   changing parameters

// for every row we are assigning the 0th column vale
// curr is current row/coulmn & that curr's 0th row has to be assigned everywhere

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;

        for (int i = 1; i <= m; i++)
        {
            if (p[i - 1] == '*')
            {
                prev[i] = prev[i - 1];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            curr[0] = false;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};

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