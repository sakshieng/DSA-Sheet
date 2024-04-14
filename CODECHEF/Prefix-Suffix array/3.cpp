#include <bits/stdc++.h>
using namespace std;
/*
Sample Input 
1
4 3
3 12 8 32
4 11 10 15
3
2
4

Sample Output 
Shyam 25
Draw 15
Ram 55
*/
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        int n;cin>>n;
        int q;cin>>q;
        
        int a[n],b[n];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        for(int i=1;i<n;++i) a[i] += a[i-1];
        for(int i=1;i<n;++i) b[i] += b[i-1];
        while(q--){
            int m;cin>>m;m--;
            if(a[m] > b[m]) cout<<"Ram"<<" "<<a[m]<<endl;
            else 
            if(a[m] < b[m]) cout<<"Shyam"<<" "<<b[m]<<endl;
            else cout<<"Draw"<<" "<<a[m]<<endl;
        }
    }
    return 0;
}