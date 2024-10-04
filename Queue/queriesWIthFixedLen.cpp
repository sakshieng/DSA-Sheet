#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
using namespace std;
vector<int> solve(vector<int> arr, vector<int> queries)
{
    int n = arr.size();
    vector<int> results;

    for (int k : queries)
    {
        deque<int> dq;
        vector<int> max_in_windows;
        for (int i = 0; i < k; ++i)
        {
            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        max_in_windows.push_back(arr[dq.front()]);
        for (int i = k; i < n; ++i)
        {
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            max_in_windows.push_back(arr[dq.front()]);
        }
        results.push_back(*min_element(max_in_windows.begin(), max_in_windows.end()));
    }

    return results;
}

