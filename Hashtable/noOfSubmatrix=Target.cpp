#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //prefix sum for each row
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j-1];
        int ans = 0;
        //try all pairs of columns
        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = col1; col2 < n; col2++)
            {
                unordered_map<int,int>mp;
                int curr = 0;
                for (int row = 0; row < m; row++)
                {
                    if(col1 == 0)
                        curr += matrix[row][col2];
                    else
                        curr += matrix[row][col2]-matrix[row][col1-1];
                    if(curr == target)
                        ans++;
                    if(mp.find(curr-target)!=mp.end())
                        ans += mp[curr-target];//curr-target is in map
                    mp[curr]++; 
                }
            }
        }
        return ans;
    }
};