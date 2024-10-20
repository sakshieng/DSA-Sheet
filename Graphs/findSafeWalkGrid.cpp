// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//Use 01 BFS

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> minHealth(n,vector<int>(m,-1));
        queue<pair<int,int>>q;

        q.push({0,0});
        minHealth[0][0] = health - grid[0][0];
        vector<int>dirn = {0,1,0,-1,0};
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                
                int newR = x + dirn[i];
                int newC = y + dirn[i+1];
                if(newR >= 0 && newC >= 0 && newR < n && newC < m){
                    //is valid
                    int newHealth = minHealth[x][y] - grid[newR][newC];

                    if(newHealth > 0 && newHealth > minHealth[newR][newC])
                    {
                        minHealth[newR][newC] = newHealth;
                        q.push({newR,newC});
                    }
                }
            }    
        }
        return minHealth[n-1][m-1] > 0;
    }
};