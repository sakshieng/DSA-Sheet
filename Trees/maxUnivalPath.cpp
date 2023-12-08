#include<bits/stdc++.h>
//https://leetcode.com/problems/longest-univalue-path/
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
//dfs
    int depth(TreeNode *root,int &dis){
        if(!root) return 0;
        int leftNode = depth(root->left,dis);
        int rightNode = depth(root->right,dis);
        int deltaR = ((root->left && root->val == root->left->val)!=0) ? leftNode+1:0;
        int deltaC = ((root->right && root->val == root->right->val)!=0)? rightNode+1:0;
        dis = max(dis,deltaR+deltaC);//so for maximize the path of same val
        return max(deltaR,deltaC);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int dis = 0;
        depth(root,dis);
        return dis;
    }
};