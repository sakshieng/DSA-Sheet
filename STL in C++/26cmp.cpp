#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// this is comparator operator means if swap krna hai toh false return otherwise true return
// > is descen and < is ascen
// here we ended up needing to sort first element chya respect mdhe sort 
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first != b.first)
    {
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main()
{
   int n;
   cin >> n;
   vector<pair<int,int>>a(n);
   for(int i=0;i<n;++i)
   {
        cin>>a[i].first>>a[i].second;
   }
   sort(a.begin(),a.end(),cmp);
   for(int i=0;i<n;++i)
   {
        cout<<a[i].first<<" "<<a[i].second<<endl;
   }
   cout<<endl;
   return 0;
}