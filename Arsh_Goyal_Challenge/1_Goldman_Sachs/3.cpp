#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
const int MOD = 1000000007;
#define ll long long
ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        ll ans = 1;
        for (int i = 0; i < N; i++) {
            ll x = A[i];
            ll cnt = 0;
            while (x % 2 == 0) {
                x /= 2;
                cnt++;
            }
            ans = (ans * (cnt + 1)) % MOD;
        }

        ans = (ans * power(N, M - 1)) % MOD;
        cout << ans << endl;
    }
    return 0;
}
