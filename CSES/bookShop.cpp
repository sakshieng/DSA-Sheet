#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
// features -> highest value feature -> target attriubtef2f1 price pages1000 1000
// target -> pages !!
// dp[price] = max pages
// why 2 states here?
// dp[price] = max pagesI would hav used same book twice or morewhich is not allowedonly 1 book oncedp[i][price] ensusres that if I am going to buy i + 1 th book, it has never been picked before
void solve()
{
    //0/1 knapsack 

    int n,x;
    cin >> n >> x;
    vector<int>prices(n,0);
    for (auto &&i : prices)
    {
        cin >> i;
    }
    vector<int>pages(n,0);
    for (auto &&i : pages)
    {
        cin >> i;
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));//2 states
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            //dont take curr book
            dp[i][j] = dp[i-1][j];

            if(j >= prices[i-1])
                dp[i][j] = max(dp[i][j],dp[i-1][j-prices[i-1]] + pages[i-1]);
        }
        
    }
    cout << dp[n][x] << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
        solve();
    
    return 0;
}