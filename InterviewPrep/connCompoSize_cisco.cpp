#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://maang.in/mocks/attempts/2144?problem_id=218
int dx[] = {1, -1, 0, 0};
int dr[] = {0, 0, 1, -1};
void dfs(vector<vector<int>> &grid, vector<vector<int>>&res, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<pair<int,int>>cells;
    cells.push_back({x,y});
    res[x][y] = -1;//as visited
    int compoSize = 1;
      while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dr[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && res[nx][ny] == 0) {
                res[nx][ny] = -1;
                q.push({nx, ny});
                cells.push_back({nx, ny});
                compoSize++;
            }
        }
    }
    //assign compo size to all cells
    for(auto &cell:cells){
        int cx = cell.first;
        int cy = cell.second;
        if(compoSize > 1) res[cx][cy] = compoSize;
        else res[cx][cy] = 0;
    }
}

void processGrid(vector<vector<int>>& grid, int n, int m) {
    vector<vector<int>>res = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && res[i][j] == 0) {
                dfs(grid, res, i, j);
            }
        }
    }
    //print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        processGrid(grid,n,m);
    }

    return 0;
}