#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    } 
    vector<ll> NSL;
    stack<ll>st;
    for(int i=0;i<n;i++)
    {
    while(!st.empty() && st.top()>=a[i]) st.pop(); 
        if(st.empty()) NSL.push_back(-1);
        else NSL.push_back(st.top());
        st.push(a[i]);
    }
    for(auto &&i:NSL)
    {
        cout<<i<<" ";
    }
    return 0;
}