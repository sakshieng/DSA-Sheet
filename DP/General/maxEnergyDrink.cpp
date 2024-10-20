// https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

#define ll long long
vector<vector<ll>> dp;
ll solve(vector<int> &a, vector<int> &b, int i, bool curr)
{ // curr is flag
    if (i >= a.size())
        return 0;
    if (dp[i][curr] != -1)
        return dp[i][curr];

    ll ans = 0;
    if (curr != 0)
    {
        // turn from drinking from A's arr
        ans = max(a[i] + solve(a, b, i + 1, curr), solve(a, b, i + 1, curr ^ 1));
    }
    else
    {
        ans = max(b[i] + solve(a, b, i + 1, curr), solve(a, b, i + 1, curr ^ 1));
    }
    return dp[i][curr] = ans;
}
long long maxEnergyBoost(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    dp.clear();
    dp.resize(n, vector<ll>(2, -1));
    return max(solve(a, b, 0, 1), solve(a, b, 0, 0));
}
