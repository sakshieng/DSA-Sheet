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