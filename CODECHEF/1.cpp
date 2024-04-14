//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
// https://www.codechef.com/LTIME111D/problems/ARREQU?tab=submissions
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool func(ll int a[],int n)
{
    unordered_map<ll,ll>m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int k=ceil(n/2.0);
    for(auto &i:m)
    {
        if(i.second>k) return false;
    }
    return true;
}
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        if(func(a,n)==false)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
}