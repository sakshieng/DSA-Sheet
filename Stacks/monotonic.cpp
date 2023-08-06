#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
#define ll long long int
void NSR_func(vector<ll> &NSR, ll n, stack<ll> &st, ll a[])
{
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        if (st.empty())
            NSR.push_back(-1);
        else
            NSR.push_back(st.top());
        st.push(a[i]);
    }
    reverse(NSR.begin(), NSR.end());
}
void NSL_func(vector<ll> &NSL, ll n, stack<ll> &st, ll a[])
{
    while (!st.empty())
        st.pop();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();
        if (st.empty())
            NSL.push_back(-1);
        else
            NSL.push_back(st.top());
        st.push(a[i]);
    }
}
void NGL_func(vector<ll> &NGL, ll n, stack<ll> &st, ll a[])
{
    while (!st.empty())
        st.pop();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= a[i])
            st.pop();
        if (st.empty())
            NGL.push_back(-1);
        else
            NGL.push_back(st.top());
        st.push(a[i]);
    }
}
void NGR_func(vector<ll> &NGR, ll n, stack<ll> &st, ll a[])
{
    while (!st.empty())
        st.pop();
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
}
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<ll> st;
    vector<ll> NSR;
    NSR_func(NSR, n, st, a);
    for (auto &&i : NSR)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<ll> NSL;
    NSL_func(NSL, n, st, a);
    for (auto &&i : NSL)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<ll> NGL;
    NGL_func(NGL, n, st, a);
    for (auto &&i : NGL)
    {
        cout << i << " ";
    }
    vector<ll> NGR;
    cout << endl;
    NGR_func(NGR, n, st, a);
    for (auto &&i : NGR)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}