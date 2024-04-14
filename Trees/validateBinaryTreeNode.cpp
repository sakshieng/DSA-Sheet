#include <bits/stdc++.h>
// https://leetcode.com/problems/validate-binary-tree-nodes/?envType=daily-question&envId=2023-10-17
using namespace std;

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, std::vector<int> &leftChild, std::vector<int> &rightChild)
    {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                inDegree[leftChild[i]]++;
            if (rightChild[i] != -1)
                inDegree[rightChild[i]]++;
        }

        int rootCount = -1;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                if (rootCount == -1)
                    rootCount = i;
                else
                    return false; // More than one root node
            }
        }
        if (rootCount == -1)
            return 0;
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(rootCount);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (vis[node])
                return 0;
            vis[node] = 1;
            if (leftChild[node] != -1)
                q.push(leftChild[node]);
            if (rightChild[node] != -1)
                q.push(rightChild[node]);
        }
        return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};