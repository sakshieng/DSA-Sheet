#include<bits/stdc++.h>
//https://leetcode.com/problems/course-schedule-ii/description/
using namespace std;

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}
		//vector<int>indegree(V);
		int indegree[V];
        for(int i=0;i<V;++i) indegree[i] = 0;
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
            topo.push_back(node);
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

        // If ordering has all vertices, there is no cycle
		if (topo.size() == V) return topo;
		return {};

    }
};