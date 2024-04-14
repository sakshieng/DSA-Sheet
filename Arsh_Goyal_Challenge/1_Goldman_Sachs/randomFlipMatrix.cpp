#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long help(long long n, long long b)
{
    long long result = 0;
    long long power = 1;

    while (n > 0) {
        long long even = (n + 1) / 2;  
        long long odd = n / 2;          

        if (even % 2 == 1) 
            result |= power;

        n /= b;
        power *= b;
    }
    return result;
}

long long solve(long long l, long long r, long long x)
{
    long long a = (help(r, x) ^ help(l - 1, x)) % mod; 
    return a;
}

int main()
{
    long long t;
    cin >> t;
    while (t--) {
        long long l, r, b;
        cin >> l >> r >> b;
        cout << solve(l, r, b) << "\n";
    }
    return 0;
}
