#include<bits/stdc++.h>
// https://leetcode.com/problems/path-with-minimum-effort/?envType=daily-question&envId=2023-09-16
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //{diff,{row,col}}
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0] = 0;
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,1,0,-1};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 and col==m-1) return diff;
            for(int i=0;i<4;++i){
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if(nRow>=0 and nCol>=0 and nRow<n and nCol<m){
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]),diff);
                    if(newEffort < dis[nRow][nCol]){
                        dis[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }
        return 0;//unreachable
    }
    //ElogV tc sc N*M*4*log(n*m)
};