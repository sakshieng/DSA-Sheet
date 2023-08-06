 
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
   vector<int> a(n);
    int cnt=0;
    for(int i=0;i<n;++i) cin>>a[i];
   vector<int> b(n) ;
   for(int i=0;i<n;++i) b[i] = a[i];
sort(b.begin(),b.end());
    for(int i=0;i<n;++i){
        if(a[i] != b[i]) {
        // swap(a[i],a[i+1])
        cnt++;
        }
    }
    // if(cnt == 0) cout<<0<<"\n";
   cout<<cnt/2<<"\n";
    }
    return 0;
}
