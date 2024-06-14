// https://maang.in/problems/Multiply-Sum-Query-36?resourceUrl=cs71-cp481-pl3270-rs36
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
    vector<long long> ans(n + 1, 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = (arr[i] % MOD + MOD) % MOD;
        ans[i] = (arr[i]*i)%MOD;
    }
     for(int i=1;i<=n;++i){
        arr[i] += arr[i-1];
        arr[i] %= MOD;
        ans[i] += ans[i-1];
        ans[i] %= MOD;
    }
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        long long mul = ans[r] - ans[l-1];
        mul -= (l-1)*(arr[r]-arr[l-1]);
        mul = (mul%MOD+MOD)%MOD;
        cout<<mul<<"\n"; 
    }
    
    return 0;
}