#include <bits/stdc++.h>
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        bool odd = true; // means next level is odd
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int t = q.size();
            vector<int> store;
            while (t--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left), store.push_back(node->left->val);
                if (node->right)
                    q.push(node->right), store.push_back(node->right->val);
            }
            if (odd && store.size() != 0)
            {
                t = q.size();
                int i = store.size() - 1;
                while (t--)
                {
                    // we are reversing the val at odd level
                    TreeNode *node = q.front();
                    q.pop();

                    node->val = store[i--];
                    q.push(node);
                }
            }
            odd = !odd;
        }
        return root;
    }
};