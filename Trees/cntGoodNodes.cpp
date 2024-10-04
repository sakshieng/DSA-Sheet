// https://leetcode.com/problems/count-the-number-of-good-nodes/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
class Solution
{
public:
    int ans = 0;
    int dfs(int parent, vector<vector<int>> &edges, int node)
    {
        int subtreeSize = 1;
        unordered_set<int> st;
        // node is a leaf node then also it is good
        for (auto &&i : edges[node])
        {
            if (i == parent)
                continue;
            int currSubtreeSize = dfs(node, edges, i);
            subtreeSize += currSubtreeSize;
            st.insert(currSubtreeSize);
        }
        if (st.size() <= 1)
            ans++;
        return subtreeSize;
    }
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 5);
        for (auto &i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // ;
        dfs(-1, adj, 0);
        return ans;
    }
    // }
};