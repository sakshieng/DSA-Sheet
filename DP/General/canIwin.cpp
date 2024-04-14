
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/can-i-win/description/
class Solution
{
public:
    int dp[1 << 20];
    bool dfs(int M, int T, int K)
    {
        if (T <= 0)
            return 0;
        if (dp[K] != -1)
            return dp[K];
        for (int i = 0; i < M; ++i)
        {
            if (!(K & (1 << i)) and !dfs(M, T - (i + 1), K | 1 << i))
                // means both cond are false
                // ith bit is set or not is checked in dfs
                return dp[K] = 1;
        }
        return dp[K] = 0;
    }
    bool canIWin(int maxC, int desired)
    {
        if (desired == 0)
            return 1;
        // how much total we can found so n*(n+1)/2
        int total = maxC * (maxC + 1) / 2;
        if (total < desired)
            return 0;
        if (total == maxC)
            return maxC % 2; // maxC is odd
        memset(dp, -1, sizeof dp);
        return dfs(maxC, desired, 0);
    }
};

int main()
{
    Solution solution;
    int maxC = 10;
    int desired = 12;
    bool result = solution.canIWin(maxC, desired);
    if (result)
        cout << "YEs";
    else
        cout << "NO";

    return 0;
}
