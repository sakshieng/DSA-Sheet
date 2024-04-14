#include <bits/stdc++.h> 
using namespace std;
// https://www.codingninjas.com/studio/problems/minimum-coins_982764?leftPanelTab=1
int minimumCoins(int p)
{
    vector<int>den={1,2,5,10,20,50,100,500,1000};
   int ans=0;
   while(p!=0) {
       for(int i=den.size()-1;i>=0;i--) {
           if(p/den[i]>=1) {
               p=p-den[i];
               ans++;
               break;
           }
       }
   }
   return ans;
}
#include <bits/stdc++.h>
//space optimization
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    int prev=0;
    int prev2=0;
    for(int i=0;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        ss=prev2+abs(heights[i]-heights[i-2]);
       
        
       int  curr=min(fs,ss);
        prev2=prev;
        prev=curr;
    }
    // dp.resize(n+1,-1);
    return prev;
}