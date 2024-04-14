#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge&leftPanelTab=1
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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

// we are given key find smallest val such that val>=key for greater no go to right for lower go to left
int findCeil(BinaryTreeNode<int> *root, int x)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (root->data == x)
        {
            ceil = root->data;
            return ceil;
        }
        if (x > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
// TC->O(log2n)