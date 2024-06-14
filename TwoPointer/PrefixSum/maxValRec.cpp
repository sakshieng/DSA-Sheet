// https://maang.in/problems/Max-Value-in-the-Rectangle-28?resourceUrl=cs71-cp481-pl3272-rs28
#include<bits/stdc++.h>
// sakshi codes here
//2d partial sum if u want to understand it deeply give the smaple testcase to chatgpt it will firstly generate 2d array of n*m which has 0 in it
using namespace std;
const int maxi = 1005;
long long arr[maxi][maxi];
long long prefixSum[maxi][maxi];
const long long int MOD = 1e9 + 7;
int main()
{
    long long int n;
    cin >> n;
    long long m;
    cin >> m;
    long long int q;
    cin >> q;
    
    memset(prefixSum,0,sizeof(prefixSum));//intialize with 0's
    //process each query
    while (q--)
    {
        int l,u,r,d;
        cin>>l>>u>>r>>d;
        long long c;
        cin>>c;
        prefixSum[l][u] += c;
        prefixSum[l][d+1] -= c;
        prefixSum[r+1][u] -= c;
        prefixSum[r+1][d+1] += c;
    }
    
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            if(i > 1)
                prefixSum[i][j] += prefixSum[i-1][j];
            if(j > 1)
                prefixSum[i][j] += prefixSum[i][j-1];
            if(i>1 && j>1)
                prefixSum[i][j] -= prefixSum[i-1][j-1];
            arr[i][j] = prefixSum[i][j] ;
        }
    }
    //now we need to calculate max number and then how many times it has occured in cells
    long long maxi = LLONG_MIN, maxCnt = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            if(arr[i][j] > maxi){
                maxi = arr[i][j];
                maxCnt = 1;
            }else if (arr[i][j] == maxi) {
                ++maxCnt;
            }
        }
    }
    cout<<maxi<<" "<<maxCnt<<"\n";
    return 0;
}
