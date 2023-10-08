#include <bits/stdc++.h>
using namespace std;
// https://www.codechef.com/problems/GCDQ
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        int pref[n + 10], suff[n + 10];
        
        pref[0] = suff[n+1] = 0;
          for(int i=1;i<=n;++i){
                //forward
            pref[i] = __gcd(pref[i-1],arr[i]);
        }
        for(int i=n;i >=1 ;--i){
            //backward
            suff[i] = __gcd(suff[i+1],arr[i]);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            
          
            cout<<__gcd(pref[l-1],suff[r+1])<<"\n";
        }
    }
    return 0;
    //TC->O(T*(N+N)) ->10^6
}