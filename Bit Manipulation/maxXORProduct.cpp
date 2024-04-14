// https://leetcode.com/problems/maximum-xor-product/description/
#include <bits/stdc++.h>
// no need to check x=0 & y=1 or x=1 & y=1 then we have to set X chi bit 0 means 0 sobat OR ghene no point
using namespace std;
#define ll long long
class Solution
{
public: // bit manipulation
    const int mod = 1e9 + 7;
    bool isKthBitSet(ll n, ll k)
    {
        if (n & ((ll)1 << k))
            return 1;
        else
            return 0;
    }
    int maximumXorProduct(long long a, long long b, int n)
    {
        for (ll i = n - 1; i >= 0; i--)
        {
            if (a > b)
                swap(a, b); // we want min elmt as a
            ll x = isKthBitSet(a, i);
            ll y = isKthBitSet(b, i);
            if (x == 0 && y == 0)
            {
                // then X chi bit 1 krychi
                a = (((ll)1 << i) | a);
                b = (((ll)1 << i) | b);
            }
            else if (x == 0 && y == 1)
            {
                a = (((ll)1 << i) ^ a);
                b = (((ll)1 << i) ^ b);
            }
        }
        ll res = ((a%mod)*(b%mod));
        res %= mod;
        return res;
    }
};
// when we want to maximize the product of 2 terms maximize the min term 3*5=15 4*5=20 not 3*6=18
// when a & b are closest to each other we get max product
// so what we will do we will take that x whose i^th bit is different from a given that a = min(a,b) to not make xor=0