#include <bits/stdc++.h>
// sakshi codes here
// https://codeforces.com/gym/105418/problem/G
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool isOdd(int n)
{
    return n % 2 != 0;
}
void solve()
{
    int d;
    cin >> d;
    vector<int> card(d, 0);
    for (auto &i : card)
        cin >> i;
    vector<int> tmp;
    for (auto i : card)
    {
        if (isOdd(i))
            tmp.push_back(1);
        else
            tmp.push_back(0);
        if (isPrime(i))
            tmp.back() -= 1;
    }
    int maxi = tmp[0];
    int curr = tmp[0];

    for (int i = 1; i < tmp.size(); i++)
    {
        curr = max(tmp[i], curr + tmp[i]);
        maxi = max(maxi, curr);
    }

    cout << maxi << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}