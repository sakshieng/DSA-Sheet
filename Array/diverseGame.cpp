const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);

#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
// Sakshi codes here
using namespace std;
#define Sakshi ios_base::sync_with_stdio(false);
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
//https://codeforces.com/contest/1994/problem/A
int main()
{
    // Sakshi pro
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n ;
        string s,t;cin>>s>>t;
        int pos1 = n,pos2 = n;
        for (int i=0;i<n;++i){
            if(s[i] == '1' && pos1 == n)
                pos1 = i;
            if(t[i] == '1' && pos2 == n)
                pos2 = i;
        }
        if(pos1 <= pos2) yes;
        else no;

    }

    return 0;
}
