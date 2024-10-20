#include <bits/stdc++.h>
using namespace std;
// https://maang.in/mocks/attempts/7293?problem_id=88
const int MOD = 1e9 + 7;

int findCnt(vector<int>& arr, int n, int m) {
    unordered_map<int, int> count;
    count[0] = 1; 
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> temp = count;
        for (auto& pair : temp) {
            int sum = (pair.first + arr[i]) % m;
            count[sum] = (count[sum] + pair.second) % MOD;
        }
    }
    
    return count[0] - 1; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m = 7;
        
        cout << findCnt(a, n, m) + 1 << endl;
    }
    return 0;
}
