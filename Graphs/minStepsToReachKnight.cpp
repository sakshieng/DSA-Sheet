#include<bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/minimum-steps-to-reach-target-by-a-knight_893050?leftPanelTab=1
using namespace std;

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    int x1 = knightPosition.first;
    int y1 = knightPosition.second;
    int x2 = targetPosition.first;
    int y2 = targetPosition.second;
    queue<pair<int, int>>q;
    q.push({x1-1,y1-1});//knight pos initial
    if(x1==x2 && y1==y2)return 0;
    // int steps = 
    vector<vector<int>>a(size,vector<int>(size,0));
    int row[] = {1,2,1,2,-1,-2,-1,-2};
    int col[] = {2,1,-2,-1,2,1,-2,-1};
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int r = it.first;
        int c = it.second;
        for(int i=0;i<8;++i){
            int nRow = r + row[i];
            int nCol = c + col[i];
            if(nRow>=0 and nRow<size and nCol>=0 and nCol<size and a[nRow][nCol] == 0){
                a[nRow][nCol] = 1 + a[r][c];
                q.push({nRow,nCol});
            }
        }
    }
    return a[x2-1][y2-1];
}