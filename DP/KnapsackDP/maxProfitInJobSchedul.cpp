// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    int binarySearch(vector<pair<int, pair<int, int>>> &jobs, int idx)
    {
        int low = 0, high = idx - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (jobs[mid].first <= jobs[idx].second.first)
            {
                if (jobs[mid + 1].first <= jobs[idx].second.first)
                    low = mid + 1;
                else
                    return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        // vector<tuple<int, int, int>>jobs;
        vector<pair<int, pair<int, int>>> jobs;

        for (int i = 0; i < n; i++)
        {
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }
        sort(begin(jobs), end(jobs));
        vector<int> dp(n, 0);
        dp[0] = jobs[0].second.second;
        for (int i = 1; i < n; i++)
        {
            int currentProfit = jobs[i].second.second;
//// Find the latest job that finishes before the current job starts using binary search
            int prevIdx = binarySearch(jobs, i);

            if (prevIdx != -1)
                currentProfit += dp[prevIdx];

            dp[i] = max(dp[i - 1], currentProfit);
        }
        return dp[n-1];
    }
};