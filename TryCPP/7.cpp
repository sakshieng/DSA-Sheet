
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        int n;cin>>n;
        vector<string>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        unordered_map<string,int>mp;
        string ans="";
        for(int i=0;i<n;++i){
            string str= a[i];
            if(mp.find(str) != mp.end()) continue;
            else{
                ans += str[str.size() - 2];
                ans += str[str.size() - 1];
                mp[str]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}