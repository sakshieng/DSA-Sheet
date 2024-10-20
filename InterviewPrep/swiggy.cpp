// https://maang.in/mocks/company/test/55
#include <bits/stdc++.h>
using namespace std;
#define Sakshi           ios_base::sync_with_stdio(false);
#define Pro             cin.tie(NULL);
//4.climbing stair
long long solve(long long n, long long m) {
    return n/m + (n%m) ;
}


long long main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}
//3.stock market
#include <bits/stdc++.h>
using namespace std;
long long memo(long long i, long long n, vector<long long>& a, vector<long long>& b, long long k, vector<vector<long long>>& dp) {
    if (i >= n) return 0;
    if (dp[i][k] != -1) return dp[i][k];
    long long nonPick = memo(i + 1, n, a, b, k, dp);
    long long pick = 0;
    if (a[i] <= k) {
        pick = (b[i] - a[i]) + memo(i + 1, n, a, b, k - a[i], dp);
    }
    return dp[i][k] = max(pick, nonPick);
}

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &i : a) cin >> i;

    vector<long long> b(n);
    for (auto &i : b) cin >> i;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
    cout << memo(0, n, a, b, k, dp) << "\n";
}

int main() {
    long long t;cin>>t;while(t--){
        solve();
    }
    return 0;
}
