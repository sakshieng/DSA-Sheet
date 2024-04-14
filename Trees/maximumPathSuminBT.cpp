#include <bits/stdc++.h>
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int dfs(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;
        int leftSum = max(0, dfs(root->left, maxSum));
        int rightSum = max(0, dfs(root->right, maxSum));
        maxSum = max(leftSum + root->val + rightSum, maxSum);
        return (root->val) + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        dfs(root,maxi);
        return maxi;
    }
};