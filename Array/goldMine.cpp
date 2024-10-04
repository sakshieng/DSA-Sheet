// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution{
public:
    int maxGold(int m, int n, vector<vector<int>> mat)
    {
        for(int col = n-2;col >= 0;col--){
            for(int row = 0;row < m;++row){
                int right = mat[row][col+1];
                int rightUp = (row == 0) ? 0 : mat[row-1][col+1];

                int rightDown = (row == m-1) ? 0 : mat[row+1][col+1];

                mat[row][col] += max(right,max(rightUp,rightDown));
            }
        }
        int res = mat[0][0];
        for(int i=1;i < m;++i)
            res = max(res,mat[i][0]);
        return res;
    }
};