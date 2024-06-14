#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
int solve(const string &s,const string &t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i-1] == t[j-1]) {
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s,t;cin>>s>>t;
        cout<<solve(s,t)<<"\n";
    }
    return 0;
}