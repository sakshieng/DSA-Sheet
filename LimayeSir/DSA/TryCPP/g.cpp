//Code by : SAKSHI
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000942404
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
        long long int m;
        long long int n;
        cin >> m>>n;
        long long int a[m];
            int sum=0;
        int i=0;
        for (i = 0; i < m; i++) cin>>a[i];
        {
            sum+=a[i];
        }
        int k=sum%n;
        cout<<k<<endl;
    }
    return 0;
}