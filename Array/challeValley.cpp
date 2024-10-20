// https://codeforces.com/problemset/problem/1760/D
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    ll n;cin>>n;
    vector<ll>a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int cnt = 1,flg = 1;
   for(int i=1;i<n;++i){
    if(a[i] > a[i-1]) flg = 0;
    else if(a[i] < a[i-1] && !flg) cnt = 0;
   }
     if(cnt == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }    
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}