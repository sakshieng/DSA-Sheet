#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-path-sum/description/
//microsoft question
class Solution {
public:
//space optimization
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>prev(n,0);
        for(int i=0;i<n;++i){
            vector<int>curr(m,0);
            for(int j=0;j<m;++j){
                if(i==0 && j==0) curr[j]= grid[i][j];
                else{
                    int up=grid[i][j];
                    //requiring prev rows j col
                    if(i > 0) up += prev[j];
                    else up += 1e9;//ignore up

                    int left=grid[i][j]; 
                    //curr rows j-1 col 
                    if(j > 0) left += curr[j-1];
                    else left += 1e9;

                   curr[j] = min(left,up);
                }
            }
            prev = curr;
        }
        return prev[m-1];//the for loop i=n the prev for that will be m-1
    }
};
/*
values are not unifrom hence no greedy use DP there might be some future case where less cost is there
overlapping subproblems to avoid it use memoiozation
*/

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution solution;
    int minSum = solution.minPathSum(grid);

    cout << "Minimum Path Sum: " << minSum << endl;

    return 0;
}
