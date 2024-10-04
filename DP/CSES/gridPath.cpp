#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,'0'));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*')
    {
        cout << 0 << endl;
        return;
    }
    //right i+1 / down j+1
    vector<vector<int>>dp;
    dp.resize(n+1,vector<int>(n+1,0));//initially there are no ways to reach
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i-1 >= 0){
                if(grid[i-1][j] != '*'){
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                }
            }
            if(j-1 >= 0){
                if(grid[i][j-1] != '*'){
                    dp[i][j] = (dp[i][j-1] + dp[i][j]) % mod;
                }
            }
        }
        
    }
    cout << dp[n-1][n-1] << "\n";
    return 0;
}