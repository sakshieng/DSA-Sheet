#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/combinations/description/

class Solution {
public:


void solve(int n,int k,int idx,vector<vector<int>> &ans,vector<int> &curr){
    if(k == 0){
        ans.push_back(curr);
        return;
    }
    if(idx == n+1) return;
    
    //ith elmt not present so skip
    solve(n,k,idx+1,ans,curr);
    curr.push_back(idx);
    //take
    solve(n,k-1,idx+1,ans,curr);
    curr.pop_back();
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>curr;
        solve(n,k,1,ans,curr);
        return ans;
    }
};
/*
non-identical items place nP2 and identical items placed nC2 here 4C2=6 we have to print all these combi
it will keep it/leave it 
at 1th level 1st box _ _ _ _ or i _ _ _
2^n = nC0+nC1+nC2+nC3+........+nCn
*/