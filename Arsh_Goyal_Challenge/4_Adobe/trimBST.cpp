//https://leetcode.com/problems/trim-a-binary-search-tree/description/
//Remove BST keys outside given range
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
/*
bottom to up check krt jayche 10 la trim or not 
take example
child pahila complete vhave lagnar nantr vr jaun parent
so dfs call vr asnar
node->val > high
    node delete
    node right subtree delete
    nodeparent->right la assign node->left
node->val < low
    node delete
    node left subtree delete
    nodeparent->left la assign node->right
*/
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        
        if(root->val<low)
            return trimBST(root->right,low,high);//assign krt ahe left la
        
        if(root->val>high)
            return trimBST(root->left,low,high);
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);

        return root;
    }
};