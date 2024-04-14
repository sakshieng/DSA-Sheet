// Code by : SAKSHI
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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        deque<ll> dq;
        for (ll i = 0; i < n; i++)
        {
            dq.push_back(i);
        }
        ll cnt0 = 0, cnt1 = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                cnt1++;
            else
                cnt0++;
        }
        ll ans;
        if (cnt0 == cnt1)
        {
            for (auto &x : dq)
            {
                cout << x << " ";
            }
        }
        else if (cnt1 > cnt0)
        {
            ans = cnt1 - cnt0;
            while (ans--)
            {
                ll temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            for (auto &x : dq)
            {
                cout << x << " ";
            }
        }
        else
        {
            ans = cnt0 - cnt1;
            while (ans--)
            {
                ll temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
            for (auto &x : dq)
            {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}