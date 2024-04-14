#include <bits/stdc++.h>
// https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/1089328411/?envType=daily-question&envId=2023-11-01
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
    int currNum = 0, currFreq = 0, maxFreq = 0;
    vector<int> res;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        if (root->val == currNum)
            currFreq++;
        else
            currNum = root->val, currFreq = 1;
        if (currFreq > maxFreq)
            res = {}, maxFreq = currFreq;
        if (currFreq == maxFreq)
            res.push_back(root->val);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        dfs(root);

        return res;
    }
};