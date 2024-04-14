#include <iostream>
#include <vector>

using namespace std;

string LPS(string s, char cheater)
{
    int n = s.length();
    if (n <= 1)
    {
        return s;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    int start = 0, maxLen = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == cheater || s[i + 1] == cheater)
        {
            dp[i][i + 1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (dp[i + 1][j - 1] && (s[i] == cheater || s[j] == cheater))
            {
                dp[i][j] = 1;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;

    char cheater;
    cout << "Enter the cheater character: ";
    cin >> cheater;

    string result = LPS(input, cheater);

    cout << "Longest Palindromic Substring with '" << cheater << "': " << result << endl;

    return 0;
}
