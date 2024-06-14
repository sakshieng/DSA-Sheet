#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

int solve(int k, const string &s, const string &c)
{
    int N = s.size();
    vector<bool> special(26, 0);
    for (int i = 0; i < 26; ++i)
    {
        if (c[i] == '1')
        {
            special[i] = 1;
        }
        else
        {
            special[i] = 0;
        }
    }
    int left = 0, maxi = 0, currNormalCnt = 0;
    for (int right = 0; right < N; right++)
    {
        if (!special[s[right] - 'a'])
        {
            currNormalCnt++;
        }
        while (currNormalCnt > k)
        {
            if (!special[s[left] - 'a'])
            {
                currNormalCnt--;
            }
            left++;
        }
        maxi = max(maxi, right - left + 1);
    }
    return maxi;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string S, C;
        cin >> S >> C;

        cout << solve(K, S, C) << "\n";
    }
    return 0;
}