#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int preOrder(TreeNode<int>* root,int &diameter)
  {
    if(!root) return 0;
    int l= preOrder(root->left,diameter);
    int r= preOrder(root->right,diameter);
    diameter=max(diameter,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    preOrder(root,diameter);
    return diameter;  
}