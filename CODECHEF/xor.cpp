/*
5 20 6
5   10  15  20  25

17  10  15  20  25
17  30  15  20  25
17  30  27  20  25
5   30  27  20  25
17  30  27  20  25
5   30  27  20  25
17  30  27  20  25
*/
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
        ll n, y, x;
        cin >> n >> x >> y;
        vector<ll> a(n);
        for (auto &&i : a)
        {
            cin >> i;
        }
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(a[i]);
        }
        while (y--)
        {
            ll m = pq.top();
            ll num = m ^ x;
            if (num > m)
            {
                pq.pop();
                pq.push(num);
            }
            else
            {
                if (y % 2 == 0)
                {
                    pq.pop();
                    pq.push(num);
                }
                else
                    break;
            }
        }
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    return 0;
}