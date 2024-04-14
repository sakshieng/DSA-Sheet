#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
#define ll long long int
void NSR_func(vector<ll>&NSR,ll n,stack<ll>&st,ll a[])
{
    for(int i=n-1;i>=0;i--)
    {
    while(!st.empty() && st.top()>=a[i]) st.pop(); 
        if(st.empty()) NSR.push_back(-1);
        else NSR.push_back(st.top());
        st.push(a[i]);
    }
    reverse(NSR.begin(),NSR.end());
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    } 
    vector<ll>NSR;
    stack<ll>st;
    NSR_func(NSR,n,st,a);
    for(auto &&i:NSR)
    {
        cout<<i<<" ";
    }
    return 0;
}