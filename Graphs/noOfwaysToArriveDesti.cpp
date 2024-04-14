// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
#include<bits/stdc++.h>
//it is asking no of shortest ways to reach destination
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({ it[1], it[2] });
            adj[it[1]].push_back({ it[0], it[2] });
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({ 0, 0 });
        int mod = 1e9 + 7;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();


            for (auto it : adj[node]) {
                long long adjNode = it.first;
                long long edgeNode = it.second;
                //this is 1st time i am coming with this short dist
                if (dis + edgeNode < dist[adjNode]) {
                    dist[adjNode] = dis + edgeNode;//for coming this node we are coming by adj node
                    pq.push({ dis + edgeNode, adjNode });
                    ways[adjNode] = ways[node];
                } else if (dis + edgeNode == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return static_cast<int>(ways[n - 1] % mod);
    }
};
