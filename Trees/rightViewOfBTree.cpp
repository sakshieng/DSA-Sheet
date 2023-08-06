#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/binary-tree-right-side-view/   
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
    vector<int> answer;
    vector<int> rightSideView(TreeNode* root) {
        answer.clear();
        if(root == NULL){
            return answer;
        }
        dfs(root,0);
        return answer;
    }
    void dfs(TreeNode* root,int lvl){
        if(root == NULL){
            return;
        }
        if(lvl == answer.size()){
            answer.push_back(root->val);
        }
        // do the level order traversal
        dfs(root->right,lvl+1);
        dfs(root->left,lvl+1);

    }
};  
//in left view just dfs(root->left) then dfs(root->right)
//TC->O(n) SC->O(h) height of tree