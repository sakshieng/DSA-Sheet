#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/mother-vertex/1
class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    //condensation graph

    vector<int> order;
    
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto &i : adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
        order.push_back(node);
    }
    
    void dfs2(int node, vector<int>& vis, vector<int> adj[], int& rem) {
        vis[node] = 1;
        --rem;
        for(auto &i : adj[node]) {
            if(!vis[i]){
                dfs2(i, vis, adj, rem);
            }
        }
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        // Step 1: Perform a DFS to get the order of vertices by their finishing times.
        for(int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, vis, adj);
            }
        }
        
        fill(vis.begin(), vis.end(), 0);
        int last_vertex = order.back();
        int rem = V;
        dfs2(last_vertex, vis, adj, rem);
    
        return rem == 0 ? last_vertex : -1;
 	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}