#include<bits/stdc++.h>
//https://leetcode.com/problems/maximal-network-rank/
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //no of roads for 0=2 for 1=3 2+3-1 for repeating 
        //we will create a mtrix for directly connc compo
        vector<vector<int>>dirn(n,vector<int>(n,0));
        vector<int>cnt(n,0);
        //preprocessing
        for(auto &it:roads){
            cnt[it[0]]++;
            cnt[it[1]]++;
            dirn[it[0]][it[1]] = 1;//there is road betn these pair of nodes so fill 1 in matrix
            dirn[it[1]][it[0]] = 1;
        }
        int rank = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                rank = max(rank,cnt[i]+cnt[j]-dirn[i][j]);//- for if there is direct road betn nodes subtract it
            }
        }
        return rank;
    }
};