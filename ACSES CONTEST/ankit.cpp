// Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll arr[n];
        int ans=0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] < 0)
            {
                ans+=arr[i];
            }
        }
        cout << ans*x*(-1) << endl;
    }
    return 0;
}