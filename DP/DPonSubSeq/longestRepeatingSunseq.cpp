#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

    int findLongestRepeatingSubSeq(string str)
    {
        int n = str.length();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {

                if (str[i] == str[j] && i != j)
                    ans = 1 + next[j + 1];
                else
                    ans = max(next[j], curr[j + 1]);
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int LongestRepeatingSubsequence(string str)
    {

        return findLongestRepeatingSubSeq(str);
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
}