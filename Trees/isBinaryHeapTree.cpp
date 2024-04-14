/*
2 types of binary heap tree
minHeap->if all parents nodes are lesser than its children nodes
minHeap->if all parents nodes are greater than its children nodes

for given binary tree to be considered as heap -> it should be complete tree
& follow max or min heap description written above

*/
//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//https://www.codingninjas.com/studio/problems/is-binary-heap-tree_893136?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
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
int totalNodes(BinaryTreeNode<int>* root){
    if(!root)
        return 0;
    return (1 + totalNodes(root->left) + totalNodes(root->right));
}
//complete tree or not
bool isCBT(BinaryTreeNode<int>*root,int idx, int n){
    if(!root)
        return 1;//single node is complete tree
    if(idx >= n)
        return 0;
    else
        return (isCBT(root->left,2*idx+1,n) && isCBT(root->right,2*idx+2,n));
}
//check max heap or not
bool isMaxHeap(BinaryTreeNode<int>*root){
    if(!root->left && !root->right)
        return 1;//single root is max heap
    else 
        if(!root->right)
            return (root->data > root->left->data);
        else
        //means we have right may or may not have left so do recursion
            return (isMaxHeap(root->left) && isMaxHeap(root->right)) && (root->data >= root->left->data && root->data >= root->right->data);
}
bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    int n = totalNodes(root);
    return (isCBT(root,0,n) && isMaxHeap(root));
}


