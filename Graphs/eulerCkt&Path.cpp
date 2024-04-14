// https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
#include<bits/stdc++.h>
//a circuit that uses every edge of a graph exactly once
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>adj[],vector<int>&vis){
        vis[node] = 1;
        for(auto it:adj[node])
            if(!vis[it])
                dfs(it,adj,vis);
    }
	int isEulerCircuit(int v, vector<int>adj[]){
	    int tmp = 0;
        vector<int>vis(v,0);
        for (int i = 0; i < v; i++)
        {
            if(!vis[i]){
                dfs(i,adj,vis);
                tmp++;
            }
        }
        vector<int>degree(v,0);
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            degree[i] = adj[i].size();
            if(degree[i]%2 == 0)
                cnt++;
        }
        if(cnt == v and tmp == 1)
            return 2;
        else if(cnt == v-2)
                return 1;
             else
                return 0;
	}
};
