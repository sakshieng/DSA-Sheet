#include<bits/stdc++.h>
//https://codeforces.com/contest/1862/problem/B
using namespace std;

int main()
{
   int t;cin>>t;while(t--){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;++i){
        if(ans[ans.size()-1] <= a[i]) ans.push_back(a[i]);
        else{
            ans.push_back(max(a[i]-1,1));
            ans.push_back(a[i]);

        }
    }
    cout<<ans.size()<<"\n";
    for(auto &i:ans) cout<<i<<" ";
    cout<<"\n";
   }
   return 0;
}