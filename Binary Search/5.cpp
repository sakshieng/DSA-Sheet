#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
//  FIND n^th ROOT USING BINARY SEARCH

// as in 1 to 2 there are 10^d search places 2 to 3 10^d decimal places


// TC-->p*log(N*(10^d))-->d=decimal places accuracy,p=pth root of number N

double eps = 1e-6;
double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans *= mid;
    }
    return ans;
}
int main()
{
    int n;
    double x;
    cin >> x >> n;
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = lo + (hi - lo) / 2;
        if (multiply(mid, n) < x)
        // for root mid into mid 2 times
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    cout << lo << endl; // or could be hi as well
    cout << setprecision(10) << lo << " " << hi << endl;
    // means upto 5 decimal same value and 10 decimal print hotil
    cout << pow(x, 1.0 / n) << endl;
    return 0;
}