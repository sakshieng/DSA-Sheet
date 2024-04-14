#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode *formation(vector<int> &postOrder, vector<int> &inorder, unordered_map<int, int> &indexMap, int &rootIndex, int left, int right)
    {
        if (left > right)
            return NULL;
        int i = indexMap[postOrder[rootIndex]]; // the index in the inorder array in constant time

        rootIndex--;
        TreeNode *root = new TreeNode(inorder[i]); // initialization of the root node using inorder value
        root->right = formation(postOrder, inorder, indexMap, rootIndex, i + 1, right);
        root->left = formation(postOrder, inorder, indexMap, rootIndex, left, i - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; ++i)
        {
            indexMap[inorder[i]] = i;
        }

        int rootIndex = postorder.size() - 1;
        return formation(postorder, inorder, indexMap, rootIndex, 0, n - 1);
    }
};