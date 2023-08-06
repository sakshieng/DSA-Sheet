#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
void prefixSum(int arr[],int n,int prefixSum[])
{
    int i=0;
    prefixSum[i]=prefixSum[i-1]+arr[i];
}
int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> suf(n);
    for(int i=0;i<n;++i)
    {
        // lsum=sum(0,i-1)
        // rsum=i+1,n+1
    }
    return 0;
}