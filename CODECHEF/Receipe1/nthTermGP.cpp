#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/nth-term-of-gp_797999?leftPanelTab=0
const int mod = 1e9 + 7;
//binary exponentiation
long long solve(int r, int n){
        int m = 1e9 + 7;
        if(n ==0)
            return 1;
        long long t = solve(r,n/2) % m;
         t = (t*t) % m;
        if(n % 2 == 0)
            return (t) % m;
        else
            return (t * r) % m;
}
int nthTermOfGP(int n, int a, int r) {
    int x = (a * solve(r,n-1) % mod);
    return x % mod;
}

