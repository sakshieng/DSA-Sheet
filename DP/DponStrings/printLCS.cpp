// TC O(n+m) u are going in rectangle starting from n,m to 0,0
// SC O(n+m) for storing all lcs

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

string lcs(const string &s1, const string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // we have built this dp matrix for lcs
    }

    int lcsLen = dp[n][m]; // so this is answer length of lcs
    int idx = lcsLen - 1;
    string str = "";
    for (int k = 1; k <= lcsLen; k++)
    {
        str += '%'; // dummy str of that muc length create
    }
    int i = n, j = m; // idxes which are traversing over dp matrix
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str[idx] = s1[i - 1];
            i--;
            j--;
            idx--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is ";
    cout<<lcs(s1, s2);
    return 0;
}