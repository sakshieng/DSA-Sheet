#include <bits/stdc++.h>
using namespace std;
int power(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int modularExponentiation(int x, int n, int m)
{
    x = 4;
    n = 5;
    m = 3;
    int ans = power(x, n, m);
    cout<<ans;
    return ans;
}