#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};



class Solution
{
public:
    void inorder(Node *root,vector<int>&vt)
    {
        if (!root)
            return;
        inorder(root->left,vt);
        vt.push_back(root->data);
        inorder(root->right,vt);
    }
    void postOrder(Node *root,vector<int>&vt,int idx)
    {
        if (!root)
            return;
        vt.push_back(root->data);
        postOrder(root->left,vt,idx);
        postOrder(root->right,vt,idx);
        root->data = vt[idx++];
    }
    void convertToMaxHeapUtil(Node *root)
    {
        vector<int>arr;
        inorder(root,arr);
        postOrder(root,arr,0);
        return;
    }
    //https://www.geeksforgeeks.org/problems/check-if-subtree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
    bool isSame(Node* a,Node* b){
        if(a == nullptr && b == nullptr)
            return 1;
        if(a == nullptr || b == nullptr)
            return 0;
        return isSame(a->left,b->left) && isSame(a->right,b->right) && (a->data == b->data);
    }
    bool isSubTree(Node* t, Node* s) 
    {
        //s is present in subtree t or not
        if(s == nullptr)
            return 1;
        if(t == nullptr)
            return 0;
        if(isSame(t,s))
            return 1;
        return isSubTree(t->left,s) || isSubTree(t->right,s);
    }
};
