// https://leetcode.com/problems/delete-node-in-a-bst/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution {
public:
    TreeNode* help(TreeNode *root){
        if(root->right == NULL) return root->left;
        else if(root->left == NULL) return root->right;
        else if(root->left == NULL && root->right == NULL) return NULL;
        else{
            TreeNode* leftRightMost = root->left;	
            while(leftRightMost->right){
                leftRightMost = leftRightMost->right;
            }
            leftRightMost->right = root->right;
        }
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            return help(root);
        }
        return root;
    }
};