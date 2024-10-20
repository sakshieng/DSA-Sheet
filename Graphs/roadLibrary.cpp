// https://www.hackerrank.com/challenges/torque-and-development/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
vector<int> adj[100005];
bool vis[100005];
long nodes;

void dfs(int n)
{
    nodes++;
    vis[n] = 1;
    for (auto &i : adj[n])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> &cities)
{
    // Clear adjacency list and visited array
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = 0;
    }

    for (int i = 0; i < cities.size(); i++)
    {
        int a = cities[i][0];
        int b = cities[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long cost = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            nodes = 0;
            dfs(i);
            cost += c_lib;

            if (c_lib < c_road)
            {
                cost += (c_lib * (nodes - 1));
            }
            else
            {
                cost += (c_road * (nodes - 1));
            }
        }
    }
    return cost;
}
