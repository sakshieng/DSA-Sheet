// Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    string s;
    cin >> s;
    ll cnt1 = 0, cnt0 = 0;
    cnt0 = count(s.begin(), s.end(), '0');
    cnt1 = count(s.begin(), s.end(), '1');
    ll k = cnt1 - cnt0;
    if (cnt0 > cnt1)
    {
        k = n - ((cnt0 - cnt0) % n);
        // %n becauz value might get greater than n
    }
    k = k % n;
    // cancel all full rotations
    reverse(a.begin(), a.end() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
    for (ll &i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}