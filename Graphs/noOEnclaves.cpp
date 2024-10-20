// https://leetcode.com/problems/number-of-enclaves/
#include<bits/stdc++.h>
//multi source bfs
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Push boundary cells into the queue and mark them as visited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Visit the neighbors
            for (int i = 0; i < 4; ++i) {
                int newR = row + delRow[i];
                int newC = col + delCol[i];
                if (newR >= 0 && newR < n && newC >= 0 && newC < m && vis[newR][newC] == 0 && grid[newR][newC] == 1) {
                    q.push({newR, newC});
                    vis[newR][newC] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 and vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    //i solved first time in multi source bfs but this would be by dfs
    
};
