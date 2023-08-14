#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://www.codingninjas.com/studio/problems/path-in-a-tree_3843990?leftPanelTab=1
#include <bits/stdc++.h>
template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};
bool getPath(TreeNode<int> *root, vector<int> &arr, int x)
{
    if (!root)
        return 0;
    arr.push_back(root->data);
    if (root->data == x)
        return 1;
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) // if any of them is returning 1 i will return 1
        return 1;
    arr.pop_back();
    return 0;
}
// TC->O(n) as inorder SC O(height of tree)
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> arr;
    if (!root)
        return arr;
    getPath(root, arr, x);
    return arr;
}
