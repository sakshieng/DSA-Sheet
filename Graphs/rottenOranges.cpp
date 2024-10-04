#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
//bfs 
// https://leetcode.com/problems/rotting-oranges/submissions/
// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

class Solution
{

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // {{row, column}, time}
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        int cntFresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if cell contains rotten orange
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    // mark as visited (rotten) in visited array
                    vis[i][j] = 2;
                }
                // if not rotten
                else
                {
                    vis[i][j] = 0;
                }
                // count fresh oranges
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int time = 0;
        // delta row and delta column
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;

        // bfs traversal (until the queue becomes empty)
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            // take max time at which all oranges are rotten
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                // neighbouring row and column
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                // check for valid cell and
                // then for unvisited fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        // if all oranges are not rotten
        if (cnt != cntFresh)
            return -1;

        return time;
    }
};

// check all are rotten or not
//  for(int i=0;i<n;++i){
//      for(int j=0;j<m;++j){
//      if(visited[i][j] != 2 && grid[i][j] == 1)
//          return -1;
//  }
//  }
//{ Driver Code Starts.
int main()
{
    vector<vector<int>> grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";
    return 0;
}
