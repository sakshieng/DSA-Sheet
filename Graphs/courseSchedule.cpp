
// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1
// https://practice.geeksforgeeks.org/problems/course-schedule/1
// https://leetcode.com/problems/course-schedule/
// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool isPossible(int V, int N, vector<pair<int, int>> &prerequisites)
	{
		vector<int> adj[V];
		for (auto it : prerequisites)
		{
			adj[it.first].push_back(it.second);
		}
		// 		vector<int>indegree(V);
		int indegree[V] = {0};
		for (int i = 0; i < V; i++)
		{
			for (auto it : adj[i])
			{
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		int cnt = 0;
		// 		vector<int> topo;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cnt++;

			for (auto it : adj[node])
			{
				indegree[it]--;
				if (indegree[it] == 0)
					q.push(it);
			}
		}

		// If ordering has all vertices, there is no cycle
		if (cnt == V)
			return 1;
		return 0;
	}
};
