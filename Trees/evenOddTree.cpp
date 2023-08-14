#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/even-odd-tree/
// nodes which are at even level so odd data and vice-versa -> can do this by DFS
// for even level left to right data increasing for odd level left to right data decreasing
// find depth of tree of that size we have to make arr

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
    static int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    vector<int> preData;

    bool check(TreeNode *root, int level)
    {
        if (root == nullptr)
            return true;

        if (level % 2 == 0)
        {
            if (root->val % 2 == 0)
                return false;
            if (preData[level] >= root->val)
                return false;
            preData[level] = root->val;
        }
        else
        {
            if (root->val % 2 == 1)
                return false;
            if (preData[level] <= root->val)
                return false;
            preData[level] = root->val;
        }

        return check(root->left, level + 1) && check(root->right, level + 1);
    }

    bool isEvenOddTree(TreeNode *root)
    {
        int depth = height(root);
        preData.resize(depth);

        for (int i = 1; i < depth; i += 2)
        {
            preData[i] = INT_MAX;
        }

        return check(root, 0);
    }
};
