#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<ll, pair<int, int>>> pq;//max heap

        for (int i = 0; i < points.size(); i++)
        {
            ll dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({dist, {points[i][0], points[i][1]}});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
    
};
