#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    // build the logic of how recursion will work
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, int preStart, int preEnd, map<int, int> &mp)
    {
        if (preStart > preEnd or inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int inLeft = inRoot - inStart;

        root->left = solve(preorder, inorder, inStart, inStart + inLeft, preStart + 1, preStart + inLeft, mp);

        root->right = solve(preorder,inorder,inRoot+1,inEnd,preStart+inLeft+1,preEnd,mp);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
            /*
            preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
            map
            9->0
            3->1
            15->2
            20->3
            7->4
            */
        }
        TreeNode *root = solve(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,mp);
        return root;
    }
};