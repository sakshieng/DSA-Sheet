#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    //i need to check my both ends are 1
    if(s[0] == '0')
    {
        s[0] = '1';
        ans++;
    }
    if(s[n-1] == '0') ans++;//end idx is also 1
   cout<<ans<<endl;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}