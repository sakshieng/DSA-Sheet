//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        map<string,int>m;
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
     string s;
     cin>>s;
    m[s]++;
   }
   int mini=0;
    for(auto &i:m)
    {
        if(i.second==0)
        mini=min(mini,i.first);
    }
    }
    return 0;
}