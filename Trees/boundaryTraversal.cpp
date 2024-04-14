// we are doing anticlock wise boundary Traversal in Binary Tree
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// we have to take left boundary excluding leaf then all leaf nodes then right boundary in reverse dirn excluding leaf nodes
//  https://www.codingninjas.com/studio/problems/boundary-traversal_790725

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
bool isLeaf(TreeNode<int> *root)
{
    return !root->left && !root->right;
}
void leftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void rightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    // as for right in revesre take boundary so store nodes in some ds
    vector<int> tmp;
    while (curr)
    {
        if (!isLeaf(curr))
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    // reverse ds and add to our ans
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        res.push_back(tmp[i]);
    }
}
void addLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left != NULL)
        addLeaves(root->left, res);
    if (root->right != NULL)
        addLeaves(root->right, res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    leftBoundary(root, res);
    addLeaves(root, res);
    rightBoundary(root, res);
    return res;
}
// TC ->right boundary+left boundary+O(N)=O(h)+O(h)+O(N)