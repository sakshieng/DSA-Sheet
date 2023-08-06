#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//tabulation
// https://leetcode.com/problems/distinct-subsequences/description/
int func(int i,int j,string s, string t,vector<vector<int>>&dp){
    if(j == 0) return 1;//bag is 0
    if(i == 0) return 0; //bagbag is 0
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]){
        return dp[i][j] = func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
    }
    return dp[i][j] = func(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,t,dp);
    }
};
int main() {
    Solution solution;
    string s = "bagbagb";
    string t = "bag";
    int result = solution.numDistinct(s, t);
    cout << "Number of distinct subsequences: " << result << endl;
    
    return 0;
}
/*count all ways so recursion with base case which 0/1 and all recu to give ans
2 strings hence two parameters i and j
how to write recurrence
1.express everything in terms of i,j
2.explore all possibilities
3.Recursion ke all possi ka summation
4.base case

TC->O(n*m)
Sc->O(n*m)+O(n*m)
            auxilary space

for tabulation
1.write down the base case
2.write chaning parameters i , j
3.copy paste the 
*/