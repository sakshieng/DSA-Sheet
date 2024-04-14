// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
#include<bits/stdc++.h>
//sakshi codes here
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
int ans = 0;
    vector<int>solve(TreeNode* root){
        if(!root)
            return {INT_MAX,INT_MIN,0};//empty tree valid BST
        auto left = solve(root->left);
        auto right = solve(root->right);
        if(left[0] < root->val && right[1] > root->val)
        //left.maxNode < root->val && right.minNode>root->val
        {
            ans = max(left[2]+right[2]+root->val,ans);
            //so bst has left che min and right che max
            return {min(left[0],root->val),max(right[1],root->val),(left[2]+right[2]+root->val)};
        }
        return {INT_MIN,INT_MAX,max(left[2],right[2])};//not a valid bst [-inf,inf]
    }
    //what are the sum of values in subtree
    //[min Sum in subtree,max val in subtree,sum of nodes in subtree]
    //[0,1,2] ase index la he store kryche
    //if i am not bst then none of my parent should be BST  
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};