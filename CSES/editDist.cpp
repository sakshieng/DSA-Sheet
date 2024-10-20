#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
// https://leetcode.com/problems/edit-distance/submissions/
int solve(string &s1,string &s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;//delete all char from s1
    }
    for(int j=0;j <= m;++j)
    {
        dp[0][j] = j;//inserting all char in s2
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];//no opn needed
            }else{
                dp[i][j] = min({
                    dp[i-1][j] + 1,//delete
                    dp[i][j-1] + 1,//insert
                    dp[i-1][j-1] + 1//replace
                });
            }
        }
    }
    return dp[n][m];
}
//dp[i][j] min no of opn 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,p;
    cin>>s>>p;
    int ans =  solve(s,p);
    cout << ans << endl;
    return 0;
}