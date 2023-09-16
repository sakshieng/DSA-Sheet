#include <bits/stdc++.h>
using namespace std;

int main()
{
  class Solution
  {
  public:
    int uniquePaths(int m, int n)
    {
      //       this reverse approach of que start from finish as it is fixed hence take up and left as que req for (0,0) tp finish is by bottom & right
      //         top to bottom ||for up i-1 j && for left j-1 i
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
      //       m+1 as 0 base index hence next to last element yeil ithe
      return gridPaths(m - 1, n - 1, dp);
    }
    int gridPaths(int i, int j, vector<vector<int>> &dp)
    {
      if (i == 0 && j == 0)
        return 1;
      // no of rows = no of coulmns =0 then 1 way to get at finish
      if (i < 0 || j < 0)
        return 0;
      //     it will go out of grid hence 0 paths
      if (dp[i][j] != -1)
        return dp[i][j];
      //     std cond^n of dp
      int up = gridPaths(i - 1, j, dp);
      int left = gridPaths(i, j - 1, dp);
      return dp[i][j] = up + left;
      //     all possible paths will be returned
    }
  };
  return 0;
}