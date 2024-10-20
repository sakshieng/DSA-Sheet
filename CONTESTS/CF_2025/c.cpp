#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// floyd warshall
//  finding shortest paths in a directed weighted graph with positive or negative edge weights
// https://leetcode.com/problems/network-delay-time/description/

int networkDelayTime(vector<vector<int>> &time, int n, int k)
{
    vector<vector<long>> dist(n, vector<long>(n, INT_MAX));
    for (auto &&i : time)
    {
        dist[i[0] - 1][i[1] - 1] = i[2];
    }
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;
    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
            }
        }
    }
    long res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (dist[k - 1][i] == INT_MAX)
            return -1;
        res = max(res, dist[k - 1][i]);
    }
    return (int)res;
}

// Eulearian Path
// Is an algorithm that finds a path that uses every edge in a graph only once.
// https://leetcode.com/problems/reconstruct-itinerary/
void dfs(unordered_map<string, multiset<string>> &graph, vector<string> &res, string start)
{
    while (graph[start].size() > 0)
    {
        auto next = *graph[start].begin();
        graph[start].erase(graph[start].begin());
        dfs(graph, res, next);
    }
    res.push_back(start);
}
vector<string> findItineary(vector<vector<string>> &tickets)
{
    unordered_map<string, multiset<string>> graph;
    for (auto &i : tickets)
        graph[i[0]].insert(i[1]);
    // starting node is "JFK"
    vector<string> res;
    dfs(graph, res, "JFK");
    reverse(res.begin(), res.end());
    return res;
}

//diameter of undirected weighted graph
const int inf = INT_MAX;
vector<int>bfs(vector<vector<int>>& graph,int source){
    int n = graph.size();
    vector<int>dist(n,inf);
    queue<int>q;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto &&v : graph[u])
        {
            if(dist[v] == inf)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        
    }
    return dist;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>& graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int diameter = 0, radius = INF;

    for (int i = 0; i < n;++i)
    {
        //pratek node ch pratek node prynt ch dist
        vector<int>dist = bfs(graph,i);
        int maxDist = 0;
        for(int k:dist)
        {
            if(d != inf)
            {
                maxi = max(maxi,d);
            }
        }
        diameter = max(diameter,maxi);
        radius = min(radius,maxi);
    }
    cout << "Diameter " << diameter << endl;
    cout << "Radius " << radius << endl;
}

//topo sort in DAG by BFS sc O(n) tc O(v+e)
vector<int>topoSort(int vertex,vector<vector<int>>& graph){
    int indegree[vertex] = {0};
    for (int i = 0; i < vertex; i++)
    {
        for(auto &it:graph[i])
            indegree[it]++;
    }
    queue<int>q;
    //jo start cha node asel
    for (int i = 0; i < vertex; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int>ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // node is in your topo sort
        // so please remove it from the indegree
        for(auto it:adj[node])  
        {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
//topo sort using DFS tc = O(V + E) sc = O(V)
void dfsTopo(int node,vector<vector<int>>& graph,vector<int>&vis,stack<int>&st){
    vis[node] = 1;
    for(auto it:graph[node])
    {
        if(!vis[it])
        {
            dfs(it,graph,vis,st);
        }
    }
    st.push(node);
}
vector<int>topoSolve(int vertex,vector<vector<int>>&graph)
{
    vector<int>vis(vertex,0);
    stack<int>st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    vector<int>ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}