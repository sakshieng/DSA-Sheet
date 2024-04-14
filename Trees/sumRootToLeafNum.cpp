#include<bits/stdc++.h>
//https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
int ans = 0;
void help(TreeNode* root,int val){
    if(!root->left && !root->right)//leaf node
    {
        val = val*10 + (root->val);
        ans += val;
        return;
    }
    val = val*10 + (root->val);
    if(root->left)
        help(root->left,val);
    if(root->right)
        help(root->right,val);
}
    int sumNumbers(TreeNode* root) {
        help(root,0);
        return ans;
    }
};