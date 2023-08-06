#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://www.codingninjas.com/studio/problems/median-of-a-bst_893184?leftPanelTab=0
// TC O(N) SC O(1)

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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int> *root, vector<int> &v)
{
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int medianBST(TreeNode<int> *root)
{
    vector<int> ans;
    inorder(root, ans);
    int n = ans.size();
    if (n % 2 == 0)
        return (ans[n / 2] + ans[n / 2 - 1]) / 2;
    else
        return ans[n / 2];
}

