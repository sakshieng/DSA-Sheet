#include <bits/stdc++.h>
// ugly number 1
//  https://leetcode.com/problems/ugly-number/description/
//  https://maang.in/mocks/attempts/2331?problem_id=63
//  https://leetcode.com/problems/ugly-number-ii/description/
//  https://www.naukri.com/code360/library/ugly-numbers-2
using namespace std;

unordered_set<int> good = {2, 3, 5};

bool ugly(int a, int base)
{
    if (good.find(a) != good.end())
    {
        return true;
    }
    if (a % base != 0)
    {
        return false;
    }
    int new_a = a / base;
    return ugly(new_a, 2) || ugly(new_a, 3) || ugly(new_a, 5);
}

bool isUgly(int n)
{
    if (n < 1)
        return false;
    if (n == 1)
        return true;

    return ugly(n, 2) || ugly(n, 3) || ugly(n, 5);
}
int nthUgly(int n)
{
    int dp[n];                  // to store ugly no.
    int p2 = 0, p3 = 0, p5 = 0; // pointers
    dp[0] = 1;
    int nextUgly;
    for (int i = 1; i < n; i++)
    {
        dp[i] = nextUgly = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
        if (nextUgly == dp[p2] * 2)
            p2++;
        if (nextUgly == dp[p3] * 3)
            p3++;
        if (nextUgly == dp[p5] * 5)
            p5++;
    }
    return dp[n - 1];
}
int main()
{
    // print  the nth ugly number with for loop
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << nthUgly(n) << endl;
    }
    return 0;
}