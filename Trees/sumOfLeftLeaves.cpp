#include <bits/stdc++.h>
//https://leetcode.com/problems/sum-of-left-leaves/
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
    int value;
    void sum(TreeNode *root, bool flg)
    {
        // set flg to oppsite when we go to right side
        if (root->left == NULL && root->right == NULL && flg == 1)
        {
            value += root->val;
            return;
        }
        if (root->left)
            sum(root->left, 1);
        if (root->right)
            sum(root->right, 0);
        return;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        if (root->left)
            sum(root->left, 1);
        if (root->right)
            sum(root->right, 0);
        return value;
    }
};