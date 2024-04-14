#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10//
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
//convert to graph & do dfs
    int maxi = 0;
    int dfs(TreeNode* root, int start){
        int depth = 0;
        if(!root)
            return depth;
        int leftDepth = dfs(root->left, start);
        int rightDepth = dfs(root->right, start);

        if(root->val == start){
            maxi = max(leftDepth,rightDepth);
            depth = -1;
        }else if(rightDepth>=0 and leftDepth>=0){
            depth = max(leftDepth,rightDepth) + 1;
        }else{
            int ans = abs(rightDepth)+abs(leftDepth);
            maxi = max(ans,maxi);
            depth = min(leftDepth,rightDepth) - 1;
        }
        return depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return maxi; 
    }
};