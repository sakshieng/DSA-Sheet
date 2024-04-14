//https://leetcode.com/problems/find-champion-ii/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        //topo sort
        int m = edges.size();
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        for (int i = 0; i < m; ++i)
        {
            int from = edges[i][0];
            int to = edges[i][1];

            indegree[to]++;
            adj[from].push_back(to);
        }
        int ans = -1;
        vector<int> visited(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (ans == -1)
                    ans = i;
                else
                    return -1;
            }
        }
        return ans;
    }
};