// https://www.hackerrank.com/contests/codefusion-22-07/challenges/nilay-and-his-bride
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
      long long int H,h,m,n;
    cin>>H>>h>>m>>n;
    long long int ans=(h*m);
    if(ans+H>=n)
        cout<<"PAIR"<<endl;
    else
        cout<<"SINGLE"<<endl;
    
   }
   return 0;
}