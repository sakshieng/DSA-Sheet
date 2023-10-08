/*constructive thinking + DFS
we can store the all unique shapes in set ds  to store take base of shape and minus them from all vertices so that they can match
list {(0,0)(0,1)(1,0)}
{(2,3)(2,4)(3,3)} so for this base would be (2,3) subtract {(0,0)(0,1)(1,0)} hence both shapes are same
list ordering for evry vertex will be same
*/
//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
// https://www.codingninjas.com/studio/problems/distinct-island_630460?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,vector<pair<int,int>>&vec,int row0,int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        //store base coordinates
        vec.push_back({row-row0,col-col0});
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        for(int i=0;i<4;++i){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if(newRow>=0 and newCol>=0 and newRow<n and newCol<m and !vis[newRow][newCol] and grid[newRow][newCol] == 1){
                dfs(newRow,newCol,vis,grid,vec,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // int vis[n][m] = {0};
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] and grid[i][j] == 1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
//tc n*m*log(set length)+(n*m*4) set length=n*m sc n*m