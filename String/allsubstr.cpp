#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// we have given a string we have to print all non-empty substrings 
void allStr(string s,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            cout<<s.substr(i,j)<<" ";
        }
    }
}
int main()
{
   string s;
   cin>>s;
   int n=s.size();
   allStr(s,n);
   return 0;
}