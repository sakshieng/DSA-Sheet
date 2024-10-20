#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/
// easy approach to check website
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        // func for expand from center
        auto solve = [&](int l, int r)
        {
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                l--;
                r++;
                // cnt++; this time u need a str rather than len
            }
            return s.substr(l + 1, r - l + 1);
        };

        string ans = s.substr(0, 1);
        for (int i = 0; i < n - 1; i++)
        {
            string odd = solve(i, i);
            string even = solve(i, i + 1);

            if (odd.length() > ans.length())
                ans = odd;
            if (even.length() > ans.length())
                ans = even;
        }
        return ans;
    }
};