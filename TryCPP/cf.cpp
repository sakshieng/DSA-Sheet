#include <bits/stdc++.h>
using namespace std;
using namespace std;
typedef long long ll;
const int N = 300010;

ll t;
ll n, k;
 
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if(a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}
 
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		vector<pair<ll, ll>>a;
		vector<ll>b;
		cin >> n >> k;
		for (ll i = 0; i < n; i++) {
			ll num;
			cin >> num;
			a.push_back({ num, i + 1});
			a[i].first %= k;
			if (!a[i].first) {
				b.push_back(i + 1);
			}
		}
		sort(a.begin(), a.end(), cmp);
		for(ll i = a.size() - 1; i >= 0; i--)
			if (a[i].first == 0) {
				a.erase(a.begin() + i);
			}
		for (int i = 0; i < a.size(); i++) {
			b.push_back(a[i].second);
		} 
		for (ll i = 0; i < b.size(); i++)cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}