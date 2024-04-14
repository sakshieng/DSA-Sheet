#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// pair of vectors
void printVec(vector<pair<int,int> >&v)
{
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}
int main()
{
   vector<pair<int,int> >v={{1,2},{3,4},{4,5}};
   printVec(v);
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
    int x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
    // or ({x,y}); can be done
   }
   printVec(v);
   return 0;
}
