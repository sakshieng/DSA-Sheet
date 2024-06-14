#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
const int mod = 998244353;
#define ll long long
int solve(ll n, int B)
{
    if (n == 0) return 0;
    int ans = n % (B - 1);
    return (ans == 0) ? (B - 1) : ans;
}
int help(ll l, ll r, ll b)
{
    ll ans = (r - l + 1) % mod;
    ans = (ans * ((l + r) % mod)) % mod;
    ans = (ans * b) % mod;
    ans = (ans * ((mod + 1) / 2)) % mod;
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r, b;
        cin >> l >> r >> b;
        cout << help(l, r, b) << "\n";
    }

    return 0;
}