#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/START150C/problems/ARRAYSTATE
//sakshi codes here
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> ms;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < k; i++) {
        auto min_it = ms.begin();
        auto max_it = prev(ms.end());

        int min_val = *min_it;
        int max_val = *max_it;

        ms.erase(min_it);
        ms.erase(max_it);

        ms.insert(min_val + max_val);
    }

    for (auto it : ms) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
