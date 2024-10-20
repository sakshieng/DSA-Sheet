#include <bits/stdc++.h>
// sakshi codes hereṇ
using namespace std;
#define ll long long
// states dp[n]= min steps to convert 0
//(d1,d2,d3,d4) n
// transiton
// dp[n] = min(dp[n-di]+1)
// tc = #states * avg transition time
// tc = O(n)
// sc = #states = O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> dp;
    dp.resize(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = i;
        while (x > 0)
        {
            int digit = x % 10;
            x /= 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }
    int ans = dp[n];
    cout << ans << endl;
    return 0;
}