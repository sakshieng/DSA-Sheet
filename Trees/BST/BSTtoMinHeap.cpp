// https://www.codingninjas.com/studio/problems/convert-bst-to-min-heap_920498?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
void inorder(BinaryTreeNode *root, vector<int> &vt)
{
    if (root == NULL)
        return;
    inorder(root->left, vt);
    vt.push_back(root->data);
    inorder(root->right, vt);
}
void preOrder(BinaryTreeNode *root, vector<int> &vt, int &idx)
{
    if (root == NULL)
        return;
    root->data = vt[idx++];
    vt.push_back(root->data);
    preOrder(root->left, vt, idx);
    preOrder(root->right, vt, idx);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> arr;
    inorder(root, arr);
    int idx = 0;
    preOrder(root, arr, idx);
    return root;
}