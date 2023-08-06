#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/minimum-cost-path_630515?leftPanelTab=0
int minCostPath(int** cost, int n, int m, int x, int y)
{
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({cost[0][0],{0,0}});
    //mark as visited
    visited[0][0] = 1;

    //down right downRightDiagonal
    int dr[] = {1, 0, 1};
    int dc[] = {0,1,1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int dist = it.first;
        int row = it.second.first;
        int col = it.second.second;

        // source is already at the destination
        if(row == x-1 && col == y-1) return dist;

        for(int i=0;i<=3;++i){
            int newR = row + dr[i];
            int newC = col + dc[i];

            if(newR>=0 && newR < n && newC >= 0 && newC < m && !visited[newR][newC]){
                visited[newR][newC] = 1;
                pq.push({dist+cost[newR][newC],{newR,newC}});
            }
        }
    }
    return -1;
}
int main() {
    int n = 3;
    int m = 3;
    int x = 3;
    int y = 3;
    int** cost = new int*[n];
    for (int i = 0; i < n; ++i) {
        cost[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }
    int result = minCostPath(cost, n, m, x, y);
    cout << "Minimum Cost Path: " << result << endl;

}   