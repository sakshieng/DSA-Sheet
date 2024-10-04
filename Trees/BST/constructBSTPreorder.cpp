// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#include <bits/stdc++.h>
// sakshi codes here
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
class Solution {
public:
    //TC O(n log n)+O(n)->to create tree from pre & in
    //property is BST of inorder is sorted as preorder has all nodes of BST sort this

    // optimized would be use isValidTree func then solve it range of val of root is [-INT_MAX,INT_MAX] SC->recursion stack space TC->O(3N)=O(N) visit r l r so 3
    TreeNode* build(vector<int>&pre,int &i,int bound){
        if(pre.size() == i or pre[i] > bound) 
            return nullptr;//no more elmt to insert or out of bound
        TreeNode *root = new TreeNode(pre[i]);
        i++;
        root->left = build(pre,i,root->val);//every elmt in left subtree has range [i,root->val]
        root->right = build(pre,i,bound);//range is [i,bound]
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder,i,INT_MAX);
    }
};