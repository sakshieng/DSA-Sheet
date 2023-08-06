//Code by : SAKSHI
// https://www.hackerrank.com/contests/codefusion-22-07/challenges/three-friends-and-trip
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
   {
      long long int n;
      cin>>n;
      vector<ll>v(n);
      for(auto &&i:v)cin>>i;
      vector<ll>ans;
      int i,j;
      for( i=0;i<n;i++)
      {
         for ( j = i+1; j < n; j++)        
         {
            if(v[j]<=v[i])
            {
               ans.push_back(v[j]);
                break;
            }
         }
         if(j==n-1)
         {
            ans.push_back(0);
         }
      }
      int sum1=accumulate(v.begin(),v.end(),0);
      int sum2=accumulate(ans.begin(),ans.end(),0);
      cout<<sum1-sum2<<endl;
   }
   return 0;
}