#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/k-th-largest-number-bst_8230750?challengeSlug=striver-sde-challenge&leftPanelTab=0

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

// reverse inorder
void solve(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    solve(root->right, ans);
    ans.push_back(root->data);
    solve(root->left, ans);
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    vector<int> ans;
    solve(root, ans);
    if (k > ans.size())
        return -1;
    return ans[k - 1];
}
