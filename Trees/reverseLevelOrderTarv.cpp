#include <bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/reverse-level-order-traversal_764339
//  https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
using namespace std;

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            while (n--)
            {
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};