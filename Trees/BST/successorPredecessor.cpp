// https://www.naukri.com/code360/problems/predecessor-and-successor_920476?topList=top-trees-interview-questions&problemListRedirection=true&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal
//  successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal

#include <bits/stdc++.h>

class binaryTreeNode
{

public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int binarySearch(vector<int> &a, int target)
{
    int low = 0, high = a.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] < target)
        {
            low = mid + 1;
        }
        else if (a[mid] > target)
            high = mid - 1;
        else
            return mid;
    }
    return low == a.size() ? -1 : low;
}
void inOrder(binaryTreeNode *root, vector<int> &inorder)
{
    if (!root)
        return;
    inOrder(root->left, inorder);
    inorder.push_back(root->data);
    inOrder(root->right, inorder);
}
vector<int> findPreSuc(binaryTreeNode *root, int key)
{
    vector<int> inorder;
    inOrder(root, inorder);
    // binary search will give u idx at which elmt is found
    int idx = binarySearch(inorder, key);
    int predecessor = (idx > 0) ? inorder[idx-1] : -1;
    int successor = (idx < inorder.size() - 1) ? inorder[idx + 1] : -1;
    return {predecessor,successor};  
}