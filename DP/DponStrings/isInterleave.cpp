// path false then it will change path
// no of paths =no of combi
// false return if no path will reach at its end
// path true to end
// as i=1 as dp[0][0]=true
// corner hence j=0 in both cases
// segmentation fault nko mhnun dp=s2.sizeof()+1
#include <bits/stdc++.h>
//https://leetcode.com/problems/interleaving-string/
using namespace std;
// 2D VECTOR
int main()
{
  class Solution
  {
  public:
    bool isInterleave(string s1, string s2, string s3)
    {
      if ((s1.size() + s2.size()) != s3.size())
        return false;
      vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
      dp[0][0] = true;
      for (int i = 1; i <= s1.size(); i++)
        dp[i][0] = (dp[i - 1][0] && (s1[i - 1] - s3[i - 1] == 0));
      for (int i = 1; i <= s2.size(); i++)
        dp[0][i] = ((dp[0][i - 1]) && (s2[i - 1] - s3[i - 1] == 0));
      for (int i = 1; i <= s1.size(); i++)
      {
        for (int j = 1; j <= s2.size(); j++)
        {
          dp[i][j] = ((dp[i - 1][j] && s1[i - 1] - s3[i + j - 1] == 0) || (dp[i][j - 1] && s2[j - 1] - s3[i + j - 1] == 0));
        }
      }
      return dp[s1.size()][s2.size()];
    }
  };
  return 0;
}
//updated one 
/*
class Solution {
public:
vector<vector<int>>dp;
//bottom-up
bool memo(string &s1, string &s2, string &s3,int i,int j,int k){
    int n=s1.size(),m=s2.size(),o=s3.size();
    if(i>=n && j>=m && k>=o) return 1;
    if(k>=o) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i<n && s1[i]==s3[k]) {
        if(j<m && s2[j]==s3[k]) return dp[i][j] = memo(s1,s2,s3,i+1,j,k+1) || memo(s1,s2,s3,i,j+1,k+1);
        return dp[i][j] =memo(s1,s2,s3,i+1,j,k+1);
    }
    if(j<m && s2[j]==s3[k]) return dp[i][j]=memo(s1,s2,s3,i,j+1,k+1);
    return dp[i][j] = 0;
}
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+101,vector<int>(s2.size()+101,-1));
        return memo(s1,s2,s3,0,0,0);
    }
};
*/