#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input7.txt", "r", stdin);
    freopen("output7.txt", "w", stdout);
#endif
}

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	return (a / gcd(a,b)) * b;
}

ll N = 16, K = 1e3 + 5;
vector<ll> a(K), b(K), dp(1 << N, 1e9);
vector<vector<ll>> c(K);

void solve()
{
	ll n, k, x;
    cin >> n >> k >> x;
    for(ll i = 1; i <= k; i++) {
        cin >> a[i] >> b[i];
        a[i] += x;
        c[i] = vector <ll> (b[i] + 5);
        for(ll j = 1; j <= b[i]; j++) cin >> c[i][j];
    }
    dp[0] = 0;
    for(ll key = 1; key <= k; key++){
        ll boxes = 0;
        for(ll j = 1; j <= b[key]; j++)
            boxes |= (1 << (c[key][j] - 1));
        for(ll mask = 0; mask < (1 << n); mask++)
            dp[mask | boxes] = min(dp[mask | boxes], dp[mask] + a[key]);
    }
    if(dp[(1 << n) - 1] == 1e9) dp[(1 << n) - 1] = -1;
    cout << dp[(1 << n) - 1] << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}