// https://leetcode.com/problems/maximum-binary-tree-ii/

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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == nullptr or val > root->val)
            return new TreeNode(val, root, nullptr); // just like normal insertion
        return new TreeNode(root->val, root->left, insertIntoMaxTree(root->right, val));
    }
};
