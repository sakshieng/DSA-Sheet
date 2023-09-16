// linear graph who have no cycle are always bipartite
// any graph with even cycle length can also be
// no adjacent node have same color
#include <bits/stdc++.h>
// bfs
// https://leetcode.com/problems/is-graph-bipartite/description/
using namespace std;

class Solution
{
    // for multiple components
private:
    bool check(int start, int V, vector<vector<int>> &graph, int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : graph[node])
            {
                if (color[i] == -1)
                {
                    // if adjacent node is yet not colored u will give oppsoite color to node
                    color[i] = !color[node];
                    q.push(i);
                }
                // if adj has same color
                if (color[i] == color[node])
                    return 0;
            }
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; ++i)
            color[i] = -1;
        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                if (check(i, V, graph, color) == 0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};