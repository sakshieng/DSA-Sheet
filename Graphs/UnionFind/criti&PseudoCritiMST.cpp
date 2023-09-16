#include<bits/stdc++.h>
//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
//refer to python soln for explanation
using namespace std;
class Solution {
public:

class UnionFind {
public:
    UnionFind(int n) {
        par.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    int getRank(int v) {
        return rank[find(v)];
    }
    int find(int v1) {
        while (v1 != par[v1]) {
            par[v1] = par[par[v1]];
            v1 = par[v1];
        }
        return v1;
    }

    bool unionn(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2) {
            return false;
        }
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

private:
    vector<int> par;
    vector<int> rank;
};

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i); // [v1, v2, weight, oriIdx]
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& e1, const vector<int>& e2) {
            return e1[2] < e2[2];
        });
        int mst_weight = 0;

        UnionFind uf(n);
        for (const auto& e : edges) {
            int v1 = e[0];
            int v2 = e[1];
            int w = e[2];
            if (uf.unionn(v1, v2)) {
                mst_weight += w;
            }
        }
        
       vector<int> pseudo, critical;
        for (const auto& e : edges) {
            int n1 = e[0];
            int n2 = e[1];
            int edgeWeight = e[2];
            int i = e[3];

            int weight = 0;
            UnionFind uf(n);
            for (const auto& edge : edges) {
                int v1 = edge[0];
                int v2 = edge[1];
                int w = edge[2];
                int j = edge[3];
                if (i != j && uf.unionn(v1, v2)) {
                    weight += w;
                }
            }

            if (uf.getRank(n1) != n || weight > mst_weight) {
                critical.push_back(i);
                continue;
            }

            uf = UnionFind(n);
            uf.unionn(n1, n2);
            weight = edgeWeight;
            for (const auto& edge : edges) {
                int v1 = edge[0];
                int v2 = edge[1];
                int w = edge[2];
                int j = edge[3];
                if (uf.unionn(v1, v2)) {
                    weight += w;
                }
            }

            if (weight == mst_weight) {
                pseudo.push_back(i);
            }
        }
        return {critical, pseudo};
    }
};