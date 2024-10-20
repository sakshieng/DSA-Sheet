#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<tuple<int, int, int>> q;

    q.emplace(startX, startY, 0);
    visited[startX][startY] = true;

    while (!q.empty())
    {
        auto [x, y, dist] = q.front();
        q.pop();

        if (x == goalX && y == goalY)
        {
            return dist;
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.')
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny, dist + 1);
                }
                nx += dx;
                ny += dy;
            }
        }
    }

    return -1;
}
