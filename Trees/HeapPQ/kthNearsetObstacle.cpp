#include <bits/stdc++.h>
// https://leetcode.com/contest/weekly-contest-413/problems/k-th-nearest-obstacle-queries/description/using namespace std;
// logic of k closest points we need obstacles of size exactly equal to size k

class Solution
{
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k)
    {
        vector<int> ans;
        priority_queue<int> pq;
        for (auto &q : queries)
        {
            int a = q[0], b = q[1];
            int dis = abs(a) + abs(b);
            pq.push(dis);
            if (pq.size() > k)
                pq.pop();
            if (pq.size() < k)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};