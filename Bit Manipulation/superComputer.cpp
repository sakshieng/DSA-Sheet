// https://www.naukri.com/code360/contests/weekly-contest-131/13276274/problems/31006?leftPanelTabValue=PROBLEM
// n = 10^3 we can do O(n^2 log n) it is like 3 sum problem we need to fnd triplets that give xor = k
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

long long solve(long long n, long long k, vector<long long> &a)
{
    map<int, int> mp;
    for (long long i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    // all values in a are unique
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            long long c = a[i] ^ a[j] ^ k;
            if (mp.find(c) != mp.end())
            {
                if (c != a[i] && c != a[j])
                {
                    ans += mp[c];
                }
                else if (c == a[i] or c == a[j])
                {
                    if (mp[c] > 1)
                    {
                        ans += mp[c] - 1;
                    }
                }
            }
        }
    }
    // each grp is counted 3 times
    return ans / 3;
}
