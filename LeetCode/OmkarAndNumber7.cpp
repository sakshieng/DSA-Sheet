#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

ll required_numbers(ll n, ll k)
{
    ll t, h, r;

    t = 9 * pow (10, (n - 1));

    h = 8 * pow (9, (n - 1));
   
    r = t - h;
    return r;
}

ll power(ll x, ll y, ll m)
{
    if(y == 0) return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
	// cout << "A : " << a << " M : " << m << endl;
    ll g = gcd(a, m);
    // cout << "GCD : " << g << endl;
    if(g != 1) return -1;
    ll ans = power(a, m - 2, m);
    return ans;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		ans += required_numbers(i, 7);
	}
	// cout << "Ans : " << ans << endl;
	ll fans = 1;
	ll sans = modInverse((ll)pow(10, n), m);
	// cout << "SANS : " << sans << endl;
	if(sans == -1) {
		cout << sans << endl;
		return;
	}
	fans = ((sans * (ans % m)) % m);
	cout << fans << endl;
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