//Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#define ll long long
#include <bits/stdc++.h>
using namespace std;
/*
conditions:
1.no of 1's==no of 0's
2.10101010-->a
  10101011-->b
  will not give ans yes
3.for conversion in both strings at least a[i]==a[i+1] as alternate string will never give required string by reversing
*/
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        ll n;
        cin>>n;
        string a;
        string b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int cnt_a=0;
        int cnt_b=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]==a[i++]) cnt_a++;
            if(b[i]==b[i++]) cnt_b++;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b && cnt_a>0 && cnt_a>0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}