#include<bits/stdc++.h>
/*
Given a 2d arr of n*n integer, given q queries and in each query given a,b,c and d print sum of square represented by (a,b) as top left point and (c,d) as bottom right point
*/
using namespace std;
const int N=1e3+10;
int arr[N][N];
long long prefixSum[N][N];
int main()
{
   int n;cin>>n;
   for(int i=1;i <= n;++i){
    for(int j=1;j <= n;++j){
        cin>>arr[i][j];
        prefixSum[i][j] = arr[i][j]+prefixSum[i][j-1]+prefixSum[i-1][j]-prefixSum[i][j]; 
    }
   } 
   int sum = 0;
   int q;cin>>q; 
   while(q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    // for(int i=a;i<=c;++i){
    //     for(int j=b;j<=d;++j){
    //         sum += arr[i][j];
    //     }
    // }
    cout<<prefixSum[c][d]-prefixSum[a-1][b]-prefixSum[c][b-1]+prefixSum[a-1][b-1]<<"\n";
    // cout<<sum<<"\n";
   }
   return 0;
}