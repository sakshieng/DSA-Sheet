#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> out;
        int level = 0;
        // simple bfs
        while (!q.empty())
        {
            int n = q.size();
            vector<int> curr(n);
            for (int i = 0; i < n; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();
                // int idx = level ? i : (size-i-1); 
                // if (level == 0)
                // {
                //     curr[i] = tmp->val; // odd level insert like 0,1,2,3
                // }
                // else
                // {
                //     curr[n - i - 1] = tmp->val; // even level insert like 3,2,1,0
                // }
                // q.pop();
                curr[idx] = tmp->data;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            out.push_back(curr);
            level == 0 ? level = 1 : level = 0; // toggle the level by level =! level using negation
        }
        return out;
    }
};

   