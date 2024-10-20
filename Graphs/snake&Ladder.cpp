#include<bits/stdc++.h>
// https://leetcode.com/problems/snakes-and-ladders/
using namespace std;
//check out gfg too
class Solution {
public:
    struct queueEntry {
        int vertex;
        int dist;
    };

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> moves(n * n, -1);
        bool leftToRight = true;
        int index = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != -1)
                        moves[index] = board[i][j] - 1;
                    index++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] != -1)
                        moves[index] = board[i][j] - 1;
                    index++;
                }
            }
            leftToRight = !leftToRight;
        }

        vector<bool> vis(n * n, false);
        queue<queueEntry> q;

        vis[0] = true;
        queueEntry start = {0, 0};
        q.push(start);

        while (!q.empty()) {
            queueEntry qe = q.front();
            int vertex = qe.vertex;
            if (vertex == n * n - 1)
                return qe.dist;

            q.pop();

            for (int j = 1; j <= 6 && vertex + j < n * n; j++) {
                int next = vertex + j;

                if (moves[next] != -1)
                    next = moves[next];

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, qe.dist + 1});
                }
            }
        }

        return -1; 
    }
};