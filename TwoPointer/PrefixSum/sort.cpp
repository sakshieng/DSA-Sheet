#include<bits/stdc++.h>
//https://codeforces.com/contest/1996/problem/C
using namespace std;

vector<vector<int>>prefix(const string &s){
    int n = s.size();
    vector<vector<int>>prefixArr(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                prefixArr[i + 1][j] = prefixArr[i][j] + (s[i] - 'a' == j );               
            }
        }
    return prefixArr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        string a,b;cin>>a>>b;
        // vector<int> res;
        vector<vector<int>>prefixArr(n+1,vector<int>(26,0));
        auto prefixA = prefix(a),prefixB = prefix(b);
    
        for (int k = 0; k < q; k++)
        {
        int ans = 0;
            int l,r;
            cin>>l>>r;
            for (int i = 0; i < 26; i++)
            {
                int cntA = prefixA[r][i] - prefixA[l-1][i];
                int cntB = prefixB[r][i] - prefixB[l-1][i];
                ans += (abs(cntA-cntB));
            }
            cout << ans/2 <<"\n";
        }
    }
    return 0;
}