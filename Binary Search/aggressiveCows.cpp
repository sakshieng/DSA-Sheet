#include <bits/stdc++.h>
using namespace std;
//TC = O(N * log(N))
class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows)
    {
        int cntCows = 1, last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows >= cows)
                return 1;
        }
        return 0;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(stalls, mid, k) == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

