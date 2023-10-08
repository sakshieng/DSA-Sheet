#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/house-robber-iii/
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
vector<int>helper(TreeNode* root){
    if(root == NULL) return {0,0};

    vector<int> left = helper(root->left); // [I, E] - Included, Excluded
    vector<int> right = helper(root->right);

    vector<int> res(2, 0);
    res[0] = root->val + left[1] + right[1]; // I
    res[1] = max(left[0], left[1]) + max(right[0], right[1]); //whenver we are not taking root whatever is max of left righ take that

    return res;
}
    int rob(TreeNode* root) {
        vector<int>y = helper(root);
        return max(y[0],y[1]);
    }
};