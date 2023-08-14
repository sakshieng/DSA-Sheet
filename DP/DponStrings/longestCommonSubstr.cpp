#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//subsequnce cant be consecutive but substr->consecu
// https://www.codingninjas.com/studio/problems/longest-common-substring_1235207
#include <bits/stdc++.h>

int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j){
            if(str1[i-1] == str2[j-1]){
                curr[j]=1+prev[j-1];//just one line diff tp lcSubsequ
                ans = max(ans,curr[j]);
            } 
            else curr[j]=0;
        }
        prev=curr;
    } 
    return ans;
}