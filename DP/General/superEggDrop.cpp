// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/
// https://leetcode.com/problems/super-egg-drop/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
class Solution
{
public:
    int memo(int k, int n, vector<vector<int>> &dp)
    {
        if (n <= 1)
            return n;
        if (k == 1)
            return n;
        if (dp[k][n] != -1)
            return dp[k][n];
        int ans = 1000000;
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int unbroken = memo(k, n - mid, dp); // no of moves
            int broken = memo(k - 1, mid - 1, dp);
            int worstCase = 1 + max(broken, unbroken);
            if (broken < unbroken)
                low = mid + 1;
            else
                high = mid - 1;
            ans = min(ans, worstCase);
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return memo(k, n, dp);
    }
};
