
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long

ll solve(const vector<ll>& arr, ll l, ll r, ll x, ll y) {
    ll count = 0;
    for (ll i = l; i <= r; ++i) {
        if ((arr[i - 1] ^ x) <= y) {
            count++;
        }
    }
    return count;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) 
        cin >> arr[i];
    
    ll q;
    cin >> q;
    while (q--) {
        ll l, r, x, y;
        cin >> l >> r >> x >> y;
        cout << solve(arr, l, r, x, y) << endl;
    }

    return 0;
}
