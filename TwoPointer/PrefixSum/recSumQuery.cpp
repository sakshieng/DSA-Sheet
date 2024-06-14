#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://maang.in/problems/Rectangle-Sum-Query-25?resourceUrl=cs71-cp481-pl3272-rs25

const int MOD = 1e9 + 7;
int main() {
    long long int n;
    cin >> n;
    long long m;
    cin >> m;
    long long int q;
    cin >> q;
    
    vector<vector<long long>> arr(n + 1,vector<long long>(m+1,0));
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            cin>>arr[i][j];
            
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    
    
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        long long result = arr[c][d] 
                         - (b > 1 ? arr[c][b-1] : 0) 
                         - (a > 1 ? arr[a-1][d] : 0) 
                         + (a > 1 && b > 1 ? arr[a-1][b-1] : 0);
        result %= MOD;
        if(result < 0)
            result += MOD;
        cout << result << "\n";
    }
    
    return 0;
}
