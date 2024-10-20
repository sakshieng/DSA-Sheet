// https://www.naukri.com/code360/problems/connect-nodes-at-same-level_985347?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

//O(n) level order traversal

template <typename T>
class BinaryTreeNode {
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};


void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        BinaryTreeNode<int>* nexxt = NULL;
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int>*curr = q.front();
            q.pop();
            //pushing left first in queue is good practice
            if(curr->right != nullptr)
                q.push(curr->right);
            if(curr->left != nullptr)
                q.push(curr->left);
            curr->next = nexxt;
            nexxt = curr;
        }
    }
}