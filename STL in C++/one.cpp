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
        long long n;
        cin>>n;
        string s;
        cin>>s;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='0' && s[i+1]=='1')
            cout<<'10';
            else
            if(s[i]=='1' && s[i+1]=='1')
            cout<<'00';
        }
        cout<<s<<endl;
    }
    return 0;
}