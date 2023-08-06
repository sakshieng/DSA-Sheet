
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,b; cin>>n>>b;
    int cnt=0;
    vector<int> v;
    for(int i=0;i<n-1;++i){
        int x; cin>>x;
        if((x&b)==b){
            v.push_back(x);
        }
    }
    if(v.size()==0)
        no;
    else{
        int x = v[0];
        for(int i=1;i<v.size()-1;++i){
            x=x&v[i];
        }
        if(x==b)
            yes;
        else
            no;
    }
}
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        solve();
    }
    return 0;
}