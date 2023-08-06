#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;


// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    TreeNode* formation(vector<int>& preorder, vector<int>& inorder, int& rootIndex,int left,int right)
    {
      if(left>right) return NULL;//left<=right ase parynt tree banvycha
      int i=left;
      while(inorder[i] != preorder[rootIndex])
      {
          i++; //  root locate kele inorder mdhe root cha index milala
      }
       rootIndex++;
       TreeNode* root=new TreeNode(inorder[i]);
       root->val=inorder[i]; 
       root->left=formation(preorder,inorder,rootIndex,left,i-1);
       root->right=formation(preorder,inorder,rootIndex,i+1,right); 
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     int rootIndex=0;
     int n=inorder.size();
     return formation(preorder,inorder,rootIndex,0,n-1);   
    }
};  