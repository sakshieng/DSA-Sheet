#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
vector<int>tree[200001];
void solve(int src,int parent,vector<int>& ans){
    int subords = 0;
    for(int child:tree[src]){
        if(child != parent){
            solve(child,src,ans);
            subords += (1+ans[child]);
        }
    }
    ans[src] = subords;
}
int main()
{
   fast_io;
   ll t,n,m,x,i,j,k,q;
   cin>>n;
   vector<int>ans(n+1);
   fr(2,n+1){
    cin>>x;
    tree[x].push_back(i);
    tree[i].push_back(x);
   }

   return 0;
}