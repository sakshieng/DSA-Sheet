#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    // reverse inorder
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        solve(root->right, ans);
        ans.push_back(root->val);
        solve(root->left, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        solve(root, ans);
        if (k > ans.size())
            return -1;
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        return ans[k - 1];
    }
};