#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// find no of palindromic substrings in str

bool palindromeCnt(string s, int i, int j)
{
    int cnt = 0;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
        ++cnt;
    }
    return true;
}

int countSubstr(string &s)
{
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        // even len pali to handle middle elmt add +1
        int even = palindromeCnt(s, i, i + 1);
        int odd = palindromeCnt(s, i, i);
        ans += (even + odd);
    }
    return ans;
}
void solve()
{

    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
            mp[arr[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool flg = false;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (mp[arr[i][j]] == 1)
            {
                flg = true;
            }
        }
        if (flg == false)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
