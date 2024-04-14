// https://practice.geeksforgeeks.org/problems/largest-bst/1
//https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution
{
private:
    NodeValue largestBSTSubtree(Node *root)
    {
        if (!root) // empty tree is valid BST
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = largestBSTSubtree(root->left);
        auto right = largestBSTSubtree(root->right);

        //curr node is > than max in left & < than min in right
        if(left.maxNode < root->data && root->data < right.minNode)
            return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
        //otherwise [-inf,inf] means parent is not valid BST
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }

public:
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return largestBSTSubtree(root).maxSize;
    }
};
