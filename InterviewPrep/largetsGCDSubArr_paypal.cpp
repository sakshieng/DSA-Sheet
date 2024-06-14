#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

ll solve(vector<ll>&a){
    ll n = a.size();
    ll ans = -1;
    for (ll i = 0; i < n; i++)
    {
        ll cur = a[i];
        //gcd of subarr should be 1
        for (ll j = i; j < n; j++)
        {
            cur = __gcd(cur, a[j]);
            if(cur == 1){
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;cin>>n;
        vector<ll>a(n);
        for(auto &i:a) cin>>i;
        cout << solve(a) << '\n';
    }
    return 0;
}