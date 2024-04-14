#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> NGR;
    stack<ll> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= a[i])
            st.pop();
        if (st.empty())
            NGR.push_back(-1);
        else
            NGR.push_back(st.top());
        st.push(a[i]);
    }
    reverse(NGR.begin(), NGR.end());
    for (auto &&i : NGR)
    {
        cout << i << " ";
    }
    return 0;
}
