#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-islands/description/

class Solution
{
public:
    int n, m;
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;
        if (grid[i][j] == '*')
            return;
        if (grid[i][j] == '0')
            return;
        // mhnje ata visited mark kra node la
        grid[i][j] = '*';
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // nvin compon mhnje nvin island
        n = grid.size();
        m = grid[0].size();
        int island = 0;
        for (int i = 0; i < n; ++i)
        {
            // matrix--nested for loops adjcency list--for loop
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1')
                {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};
/*
void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid,i+1,j);//right
        dfs(grid,i,j+1);//upward
        dfs(grid,i-1,j);//left
        dfs(grid,i,j-1);//downward
        dfs(grid,i+1,j+1);//upward-right
        dfs(grid,i-1,j-1);//downward-left
        dfs(grid,i-1,j+1);//upward-left
        dfs(grid,i+1,j-1);//downward-right
    }
    int numIslands(vector<vector<char>>& arr) {
    int ROW = arr.size();
    int COL = arr[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] == '1') {
                count++;
                dfs(arr, i, j); // traversal starts
            }
        }
    }
    return count;
    }
};

*/