// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    const static int n = 5e4 + 10;
    int dp[n];
    int solve(int idx, vector<pair<pair<int, int>, int>> &p)
    {
        if (idx >= p.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int start = p[idx].first.first;
        int end = p[idx].first.second;
        int profit = p[idx].second;
        int nextIdx = lower_bound(p.begin(), p.end(), make_pair(make_pair(end, 0), 0)) - p.begin(); // end time cha equal or less idx mhnje apla next idx ahe
        int pick = profit + solve(nextIdx, p);
        int nonPick = 0 + solve(idx + 1, p);
        return dp[idx] = max(pick, nonPick);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<pair<pair<int, int>, int>> p;
        for (int i = 0; i < startTime.size(); i++)
        {
            p.push_back({{startTime[i], endTime[i]}, profit[i]});
        }

        memset(dp, -1, sizeof(dp));
        // we are inserting profit also in vec because we need to sort that with given start & end
        sort(begin(p), end(p));

        return solve(0, p);
    }
};
