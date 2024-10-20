#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
//https://codeforces.com/contest/2020/problem/C

long long getBit(long long n, long long i)
{
    // n chi i^th bit
    return (n >> i) & 1;
}
void solve()
{

    long long b, c, d;
    cin >> b >> c >> d;
    long long a = 0;
    for (long long i = 0; i < 61; ++i)
    {
        if (getBit(b, i) == 0 && getBit(c, i) == 1 && getBit(d, i) == 1)
        {
            cout << -1 << endl;
            return;
        }
        if (getBit(b, i) == 1 && getBit(c, i) == 0 && getBit(d, i) == 0)
        {
            cout << -1 << endl;
            return;
        }
        if (getBit(b, i) == 1 && getBit(c, i) == 1 && getBit(d, i) == 0)
        {
            // a set
            a |= (1LL << i);
        }
        if (getBit(b, i) == 1 && getBit(c, i) == 1 && getBit(d, i) == 1)
        {
            // a 0 kra
            a |= (0LL << i);
        }
        if (getBit(b, i) == 1 && getBit(c, i) == 0 && getBit(d, i) == 1)
        {
            a |= (1LL << i);
        }
        if (getBit(b, i) == 0 && getBit(c, i) == 0 && getBit(d, i) == 0)
        {
            a |= (0LL << i);
        }
        if (getBit(b, i) == 0 && getBit(c, i) == 0 && getBit(d, i) == 1)
        {
            a |= (1LL << i);
        }
        if (getBit(b, i) == 0 && getBit(c, i) == 1 && getBit(d, i) == 0)
        {
            a |= (0LL << i);
        }
    }
    cout << a << endl;

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;  
    cin >> t;
    while (t--)
    {
    solve();
    }
    return 0;
}