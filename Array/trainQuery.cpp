#include<bits/stdc++.h>
//sakshi codes here
// https://codeforces.com/contest/1702/problem/C
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    int n,k;cin>>n>>k;
    map<int,int>left,right;
    for (int i = 1; i <= n; i++)
    {
        int x ; cin >> x;
        if(left[x] == 0){
            left[x] = i;
            //when we need to maintain idx
            right[x] = i;
        }else{
            right[x] = i;
        }
    }
    while (k--)
    {
        int a,b;cin>>a>>b;
        if(left.find(a) != left.end() && left.find(b) != left.end() && left[a] <= right[b]){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}