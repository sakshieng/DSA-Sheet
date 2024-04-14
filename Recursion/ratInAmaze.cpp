#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution
{
public:
  void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
  {
    if (i == n - 1 && j == n - 1) // when  u reach desti
    {
      ans.push_back(move);
      return;
    }
    // if rat goes in 8 dirn so convert 4 if-else to for loop
    string dir = "DLRU";
    for (int idx = 0; idx < 4; ++idx)
    {
      int nextI = i + di[idx];
      int nextJ = j + dj[idx];
      if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !vis[nextI][nextJ] && a[nextI][nextJ] == 1)
      {
        vis[i][j] = 1;
        solve(nextI, nextJ, a, n, ans, move + dir[idx], vis, di, dj);
        vis[i][j] = 0;//backtrack
      }
    }
  }

  vector<string> findPath(vector<vector<int>> &m, int n)
  {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0)); // check for visites
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (m[0][0] == 1) // source should be 1
      solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> m[i][j];
      }
    }
    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends