// https://cses.fi/problemset/task/1691
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// variation of finding Eulerian circuit in undirected graph
// condn for Eulerian circuit ->> all vertics should have even degree & graph should be connec
vector<vector<pair<int, int>>> graph;
vector<int> path; // eulerian path
vector<bool>vis;//track vis edges
int n,m;
void dfs(int node)
{
    while (!graph[node].empty())
    {
        pair<int, int> edge = graph[node].back();
        int son = edge.first; // get the connected node
        int idx = edge.second;
		graph[node].pop_back();
		if (vis[idx]) { 
            continue; 
        }
		vis[idx] = true;
		dfs(son);
    }
    path.push_back(node); // add node to path after visting all node
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    graph.resize(n);  
    vis.resize(m);
    vector<int>degree(n,0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i); 
        degree[u]++;
        degree[v]++;
    }
    for (int node = 0; node < n; node++)
    {
        if(degree[node]%2 != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    dfs(0);//from first node
    if(path.size() != static_cast<size_t>(m + 1))
    {
        //all edges not vis means graph is not connc
        cout << "IMPOSSIBLE";
    }else{
        for(auto node:path)
            cout << node + 1 << " ";
    }
    return 0;
}