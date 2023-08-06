//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll>m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        bool flag=false;
        for(auto &&i:m) if(i.second%i.first !=0)flag=false;
        else flag=true;
        if( flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}