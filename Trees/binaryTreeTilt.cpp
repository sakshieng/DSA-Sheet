/*
tilt value -> abs diff of left subtree node val- right subtree node val
    4
 2      7
3  5
for root 4 we wre returning left val+right val+parent val
means for 4 3+5+2 from right side and  0+0+7 from left side
for storing it in result we will subtract right part che ans-left part che ans
*/
// https://leetcode.com/problems/binary-tree-tilt/
#include<bits/stdc++.h>
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
    int res = 0;
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = (root->left ? helper(root->left) : 0);
        int right = (root->right ? helper(root->right) : 0);
        res += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode *root)
    {
        if (root)
            helper(root);
        return res;
    }
};