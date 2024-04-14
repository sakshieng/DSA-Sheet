//https://leetcode.com/problems/map-of-highest-peak/
#include<bits/stdc++.h>
/*
multisource bfs
put all water cells in queue
*/
using namespace std;

class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    bool isSafe(vector<vector<int>>&isWater,int r,int c,vector<vector<int>>&heights){
        if(r<0 or c<0 or r==isWater.size() or c==isWater[0].size() or isWater[r][c] == 1 or heights[r][c] > 0){
            return 0;
        }
        return 1;
    }
    void bfs(vector<vector<int>>&isWater,vector<vector<int>>&heights,queue<pair<int,int>>&q){
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                int height = heights[i][j];
                for (int b = 0; b < 4; b++)
                {
                    int newR = i + dr[b];
                    int newC = j + dc[b];
                    if(isSafe(isWater,newR,newC,heights))
                    {
                        heights[newR][newC] = height+1;
                        q.push({newR,newC});
                    }
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> heights(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(isWater[i][j] == 1)
                    q.push({i,j});

        bfs(isWater,heights,q);
        return heights;        
    }
};