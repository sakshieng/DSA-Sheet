// https://cses.fi/problemset/task/1693/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// variation of finding Eulerian circuit indegree directed graph
// condn for Eulerian circuit ->> At most one node has indegree[i]-outdegree[i] = 1 & at most one node has outdegree[i] - indegree[i] = 1
// In a directed graph the exception are the start node and the end node.
vector<vector<int>> graph;
vector<int> path,indegree,outdegree; // eulerian path
int n, m;
void dfs(int node)
{
    while (!graph[node].empty())
    {
        int son = graph[node].back();
        graph[node].pop_back();
        dfs(son);
    }
    path.push_back(node); // add node to path after visting all node
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
 
    graph.resize(n + 1);
    indegree.resize(n + 1);
    outdegree.resize(n + 1);
 
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y); // it is directed graph
        // edge from u to v
        outdegree[x]++;
        indegree[y]++;
    }
 
    bool flag = true;
    for (int node = 2; node < n && flag; node++)
    {
        if (indegree[node] != outdegree[node])
        {
            flag = false;
        }
    }
    if (outdegree[1] != indegree[1] + 1 || outdegree[n] != indegree[n] - 1 || !flag)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    dfs(1);
 
    reverse(path.begin(), path.end());
    if (path.size() != m + 1 || path.back() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (auto node : path)
        {
            cout << node << ' ';
        }
    }
}