#include <bits/stdc++.h>
// https://leetcode.com/problems/image-smoother/
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        // we have to take floor of avg of 9 values in matrix
        vector<vector<int>>ans(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0, cnt = 0;
                // all possible 9 idx
                for (int x = i - 1; x <= i + 1; ++x)
                {
                    for (int y = j - 1; y <= j + 1; ++y)
                    {
                        if(x>=0 and y>=0 and x<n and y<m)//valid idx
                        {
                            sum += img[x][y];
                            cnt++;
                        }
                    }
                }
                //round up the val
                ans[i][j] = sum/cnt; 
            }
        }
        return ans;
    }
};