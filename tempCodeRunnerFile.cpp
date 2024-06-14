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
    vector<long long> prefixSum(n + 1, 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] % MOD + MOD) % MOD;
    }
     for(int i=1;i<=n;++i){
        prefixSum[i] = (prefixSum[i-1]+arr[i])%MOD;
     }
    while(q--){
        long long L,R;cin>>L>>R;
        // cout<<prefixSum[r]-prefixSum[l-1]<<"\n";
         long long sum = 0;
        for (int i = L - 1; i < R; ++i) {
            sum += (i - L + 2) * arr[i];
            sum %= MOD;
        }
        cout << sum << '\n';
    }
    return 0;
}