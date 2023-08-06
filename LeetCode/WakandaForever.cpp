#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input4.txt", "r", stdin);
    freopen("output4.txt", "w", stdout);
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

void solve()
{
	ll n, x;
	cin >> n >> x;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		if(i % 3 == 0 && i != n) ans += (arr[i - 1] + arr[i - 2] + arr[i - 3]);
		ans += arr[i - 1];
	}
	if(ans <= x * 24) cout << "YES" << endl;
	else cout << "NO" << endl;
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