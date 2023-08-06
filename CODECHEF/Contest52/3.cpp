//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; cin>>t;
while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a) cin>>i;
        string b;
        cin>>b;
        map<int,char>m;
        for (int i = 0; i < n; i++)
        {
            if(m[b[i]]!='0') m[b[i]]=a[i]; 
        }
        int mini=INT_MAX;
        for(auto &i:m)
        {
            if(i.second == '0')
            mini=min(mini,i.first);
        }                        
        cout<<mini<<endl;
    }
    return 0;
}