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
    vector<ll> NSR;       
    stack<ll>st;
    for(int i=n-1;i>=0;i--)
    {
    while(!st.empty() && st.top()>=a[i]) st.pop(); 
        if(st.empty()) NSR.push_back(n);
        else NSR.push_back(st.top());
        st.push(a[i]);
    }
    reverse(NSR.begin(),NSR.end());
    for(auto &&i:NSR)
    {
        cout<<i<<" ";
    }
    return 0;
}
// j<k left nsl
/*
for reversing stack-->
while(!st.empty())
{
    int x=st.peek;
    st2.push(x);
    st.pop();
}
*/