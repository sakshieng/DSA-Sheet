
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        if(n == 1 && m == 1 && cost[0][0] == 0) return 1;
        if (cost[0][0] == 1) return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({1, {0, 0}});
        visited[0][0] = true;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            // if(row == n-1 && col == m-1) return dist+1;
            for (int i = 0; i < 8; ++i) {
                int newR = row + dr[i];
                int newC = col + dc[i];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m && !visited[newR][newC] && cost[newR][newC]==0) {
                    visited[newR][newC] = true;
                    pq.push({dist + 1, {newR, newC}});
                    if(newR == n-1 && newC == m-1) return dist+1;
                }
            }
        }
        return -1;
    }
};
int main(){
    Solution solution;
    vector<vector<int>> cost = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    int result = solution.shortestPathBinaryMatrix(cost);
    cout << "Shortest Path: " << result << endl;

    return 0;
}