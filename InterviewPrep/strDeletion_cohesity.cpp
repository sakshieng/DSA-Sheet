// https://maang.in/mocks/attempts/2207?problem_id=71
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define int long long
const int N = 1000;
#define mod (int)(1e9 + 7)
//dp[l][r] substring s[l,l+1,l2,....r]
int solve(int l, int r, int dp[N][N], string s)
{
 
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    int res = 1 + solve(l + 1, r, dp, s);
    for (int i = l + 1; i <= r; ++i) {
        if (s[l] == s[i])
            res = min(res, solve(l + 1, i - 1, dp, s)
                               + solve(i, r, dp, s));
    }
 
    // Memoize
    return dp[l][r] = res;
}
int32_t main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int dp[N][N];
        memset(dp, -1, sizeof dp);
        cout << solve(0,n-1,dp,s) << endl;
    }
    return 0;
}