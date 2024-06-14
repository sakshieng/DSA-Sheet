// https://maang.in/problems/LR-Sum-Query-18?resourceUrl=cs71-cp481-pl3270-rs18
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
const long long int MOD = 1e9 + 7;
int main()
{
    long long int n;
    cin >> n;
    long long int q;
    cin >> q;
    vector<long long> arr(n + 1);
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] % MOD + MOD) % MOD;
    }
    //  for () {
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = (prefixSum[i - 1] + arr[i]) % MOD;
    }
    // long long int q;
    // cin >> q;
    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
        long long sum = (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD;
        cout << sum << '\n';
    }
    return 0;
}