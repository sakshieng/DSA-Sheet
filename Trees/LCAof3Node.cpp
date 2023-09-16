#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/lca-of-three-nodes_794944?leftPanelTab=0
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *lcaOfThreeNodes(BinaryTreeNode<int> *root, int node1, int node2, int node3)
{
    if (!root)
        return root;
    if (root->data == node1 || root->data == node2 || root->data == node3)
        return root;
    BinaryTreeNode<int> *l = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int> *r = lcaOfThreeNodes(root->right, node1, node2, node3);
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    if (l != NULL && r != NULL)
        return root;

    return root;
}
