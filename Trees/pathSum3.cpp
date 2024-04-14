// https://leetcode.com/problems/path-sum-iii/
#include <bits/stdc++.h>
using namespace std;

// return no of paths where sum of values along path equals targetSum
struct TreeNode
{
    long long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathSumFromRoot(TreeNode *root, long int targetSum)
    {
        int cnt = 0;
        if (root->val == targetSum)
            cnt++;
        if (root->left)
            cnt += pathSumFromRoot(root->left, targetSum - (root->val));
        if (root->right)
            cnt += pathSumFromRoot(root->right, targetSum - (root->val));
        return cnt;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        int cnt = pathSumFromRoot(root, targetSum);
        cnt += pathSum(root->left, targetSum);
        cnt += pathSum(root->right, targetSum);
        return cnt;
    }
};