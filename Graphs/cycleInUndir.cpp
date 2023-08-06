#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacNode:adj[node]){
                if(!vis[adjacNode]){
                    vis[adjacNode] = 1;
                    q.push({adjacNode,node});
                }else if(parent != adjacNode){
                    //prev visited and its not parent then no cycle
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
    //we have to find this for all compo once
        for(int i=0;i<V;++i){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
    //tC ->O(n+2E) SC->O(n)
};
#include <bits/stdc++.h>
using namespace std;

// Your Solution class and detect function here...

int main() {
    int V = 5; // vertices
    int E = 6; //edges

    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4);
    adj[4].push_back(1);

    Solution solution;
    bool hasCycle = solution.isCycle(V, adj);

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
