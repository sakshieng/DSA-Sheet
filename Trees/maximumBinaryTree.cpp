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
    // max no->root then left subarray max is left child right subarray max is right c
    TreeNode *solve(vector<int> &nums, int i, int j)
    {
        // recursive->tc O(n^2)
        if (i > j)
            return nullptr; // base case
        int p = i;          // idx of largest elmt
        for (int k = i + 1; k <= j; ++k)
            if (nums[k] > nums[p])
                p = k;
        TreeNode *root = new TreeNode(nums[p]); // val to root should be maxi
        root->left = solve(nums, i, p - 1);     // maxi in left subarray
        root->right = solve(nums, p + 1, j);    // right subarray maxi
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};