#include <bits/stdc++.h>
using namespace std;
// multisource bfs + dijkistra
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/
//01 BFS
class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &cost)
    {
        int n = cost.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j])
                {
                    q.push({0, {i, j}});
                    dis[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty())
        {
            auto it = q.front();
            int safe = it.first, row = it.second.first, col = it.second.second;
            q.pop();
            for (auto dir : dirs)
            {
                int newR = row + dir[0];
                int newC = col + dir[1];
                if (newR >= 0 && newR < n && newC >= 0 && newC < n && safe + 1 < dis[newR][newC])
                {
                    q.push({safe + 1, {newR, newC}});
                    dis[newR][newC] = safe + 1;
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dis[0][0], {0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int maxi = 0;
        while (!pq.empty())
        {
            int safe = pq.top().first, row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();
            if (row == n - 1 && col == n - 1)
            {
                return safe;
            }
            for (auto dir : dirs)
            {
                int newR = row + dir[0];
                int newC = col + dir[1];
                if (newR >= 0 && newR < n && newC >= 0 && newC < n && !visited[newR][newC])
                {
                    pq.push({min(safe, dis[newR][newC]), {newR, newC}});
                    ;
                    visited[newR][newC] = 1;
                }
            }
        }
        return maxi;
    }
};
