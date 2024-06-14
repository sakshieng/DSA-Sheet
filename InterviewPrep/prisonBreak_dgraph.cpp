// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
// this won't work
// https://maang.in/mocks/attempts/2302?problem_id=201
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long

// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
// this won't work
// https://maang.in/mocks/attempts/2302?problem_id=201
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long

signed main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> hor(n), ver(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> hor[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> ver[i];
    }
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    ll maxHor = 1, maxVer = 1;
    for (ll i = 0, j = 0; j < n; i = j)
    {
        int r = hor[i];
        while (j < n && hor[j] == r)
        {
            j++;
            r++;
        }
        maxHor = max(maxHor, j - i + 1);
    }
    for (ll i = 0, j = 0; j < m; i = j)
    {
        int c = ver[i];
        while (j < m && ver[j] == c)
        {
            j++;
            c++;
        }
        maxVer = max(maxVer, j - i + 1);
    }
    cout << maxHor * 1LL * maxVer << endl;
}