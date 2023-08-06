
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>

using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        int n;cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int diff = INT_MIN;
        for(int i=0;i<n-1;i++){
            diff = max(diff,arr[i+1]-arr[i]);
        }
        int a[n];
        for(int i=0;i<n;++i){
            a[i] = arr[i];
        }
        sort(a,a+n);
        bool flg = true;
        for(int i=0;i<n;++i){
            if(a[i] != arr[i]){
                flg = false;break;
            }
        }
        int x = ceil((float)diff/2);
        if(!flg) cout<<0<<endl;
        else cout<<max(1,x)<<endl;
    
    }
    return 0;
}