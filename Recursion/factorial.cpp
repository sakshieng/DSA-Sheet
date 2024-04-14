#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
// print factorial of number N print it in %M
// 1<=T<=10^5 1<=N<=10^5
long long fact[N];
int main()
{
    fact[0] = fact[1] = 1;
    // precomputation
    for (int i = 2; i < N; ++i)
        fact[i] = fact[i - 1] * i;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
    // TC->O(N)+O(T) in 1sec 10^7 iterations are running
    // one of the precomputation technique is hashing
    return 0;
}