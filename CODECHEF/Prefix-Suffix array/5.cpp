/*
Sample Input 
1
5 3
0 0 0 0 0
2 3
1 3
2 4

Sample Output 
3

Explanation 
After 1st query elemets from index 2 to 3 increases by 1 So array is [0,1,1,0,0]

After 1st query elemets from index 1 to 3 increases by 1 So array is [1,2,2,0,0]

After 1st query elemets from index 2 to 4 increases by 1 So array is [1,3,3,1,0]

maximum element  is 3
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
long long t; 
cin>>t;
while(t--)
    {
        int n;cin>>n;
        int q;cin>>q;
        int a[n];
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
    int l,r;
        
        while(q--){
            cin>>l>>r;
            l--;
            r--;
            a[l]++;
            if(r+l < n){
                a[r+1]--;
            }
        }
        for(int i=1;i<n;++i) a[i] += a[i-1];
        int maxi = 0;
        for(int i=0;i<n;++i){
            maxi = max(maxi,a[i]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}