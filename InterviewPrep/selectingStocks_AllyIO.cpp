#include <bits/stdc++.h>
// https://maang.in/mocks/attempts/2494?problem_id=212
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n; // no of stocks
    int s;
    cin >> s;         // savings
    vector<int> a(n); // current
    vector<int> b(n); // predicted
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
    {
        cin >> i;
    }
    vector<int> ans(s + 1, 0);//savings chya pudhun loop
    for (int i = 0; i < n; i++)
    {
        int cost = a[i];
        int profit = b[i] - cost;
        if (profit > 0)
        {
            // only take stocks which give some +ve profit
            for (int j = s; j >= cost; j--)
            {
                ans[j] = max(ans[j], ans[j - cost] + profit);
            }
        }
    }
    cout << ans[s] << '\n';

    return 0;
}
