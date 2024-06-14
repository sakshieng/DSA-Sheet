// https://leetcode.com/problems/maximum-binary-tree/description/
#include <bits/stdc++.h>
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
    TreeNode *solve(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return NULL;
        TreeNode *root = new TreeNode(0);
        auto maxIt = max_element(nums.begin() + left, nums.begin() + right); // this is iterator to max elmt in range [L,R]
        int maxIdx = maxIt - nums.begin();                                   // idx of maxElmt
        root->val = nums[maxIdx];
        root->left = solve(nums, left, maxIdx);
        root->right = solve(nums, maxIdx + 1, right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return solve(nums, 0, nums.size());
    }
};