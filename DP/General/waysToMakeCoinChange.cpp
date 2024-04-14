#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?leftPanelTab=1

vector<vector<long>>dp;
long memo(int *denominations, int n, int value,int i){
    if(i>=n) return 0;
    if(value==0) return 1;
    if(value<0) return 0;
    if(dp[i][value] != -1) return dp[i][value];
    long pick = memo(denominations,n,value-denominations[i],i);
    long nonPick = memo(denominations,n,value,i+1);
    return dp[i][value] = pick+nonPick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    dp.resize(n+1,vector<long>(value+1,-1));
    return  memo(denominations,n,value,0);
}