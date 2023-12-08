#include <bits/stdc++.h>
//https://leetcode.com/problems/cheapest-flights-within-k-stops/
using namespace std;

class Solution
{
public:
#define INT_MAX 2147483647
    int findCheapestPrice(int n, vector<vector<int>> &flights, int S, int dst, int k)
    {
        // shortest path algo with a little variation

        vector<int> dis(n, INT_MAX);
        dis[S] = 0;
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp(dis);
            for (auto x : flights)
            {
                if (dis[x[0]] != INT_MAX)
                {
                    temp[x[1]] = min(temp[x[1]], dis[x[0]] + x[2]);
                }
            }
            dis = temp;
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
/*
Djikstra algo fail for negative edge

Bellman ford algo work for directed graph both for +ve/-ve edge and fails only if there is negative cycle but it will detect negative cycle
Relax all the edges (n-1) times
Relax means->
if(dist[u]+wt < dist[v]){
    dist[v]=dist[u]+wt;
}
tC->O(n-1)+O(e)
sC->O(n)
if we relax more than n-1 times shortest dis will again reduce means we are having -ve cycle
*/