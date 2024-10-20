
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    int n,r;cin >> n >> r;
    vector<int>a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int cnt = 0, single = 0;
    for (int i = 0; i < n; i++)
    {
        single += a[i] % 2;
        cnt += (a[i] - (a[i] % 2));
        r -= (a[i] - (a[i] % 2))/2;
    }
    int remainingRows = r;
    if(remainingRows >= single){
        cout << cnt + single << endl;
    }else{
        // remaining rows are less than single
        cerr << single << " " << remainingRows << "\n";
        int doublee = single - remainingRows;
        cout << cnt + (remainingRows - doublee) << "\n";
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}