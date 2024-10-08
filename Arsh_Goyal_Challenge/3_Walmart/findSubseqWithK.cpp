// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k)
                pq.push({nums[i], i});
            else if (pq.size() == k and pq.top().first < nums[i])
            {
                pq.pop();
                pq.push({nums[i], i});
            }
        }
        vector<pair<int, int>> vec;
        while (pq.size() > 0)
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            vec.push_back({idx, val});
        }
        sort(begin(vec), end(vec));
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(vec[i].first);
        return ans;
    }
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater < >>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            if (pq.size() > k)
                pq.pop();
        }
        vector<pair<int, int>> temp;
        while (!pq.empty())
        {
            temp.push_back(pq.top());
            pq.pop();
        }
        sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });

        vector<int> ans;
        for (int i = 0; i < temp.size(); ++i)
        {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};
