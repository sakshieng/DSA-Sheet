#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int mod = 1e9;

const int MAX = 26;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> v(n), pre(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        pre[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * v[i];
        }
        bool p = 0;
        int idx1 = 0, idx2 = 0;
        mp.insert({1, 0});
        for (int i = 0; i < n; i++)
        {
            int num = pre[i] / k;
            if (num == 1 && pre[i] % k == 0)
            {
                p = 1;
                idx1 = 0;
                idx2 = i;
                break;
            }
            if (mp.count(num) && (pre[i] % k == 0))
            {
                p = 1;
                idx1 = mp[num] + 1;
                idx2 = i;
                break;
            }
            mp.insert({pre[i], i});
        }
        if (p)
        {
            cout << "Yes"<< " " << idx1 << " " << idx2 << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}