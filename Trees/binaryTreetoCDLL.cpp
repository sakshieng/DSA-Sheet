// https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1
//left pointer as prev in LL and right pointer as next in LL
#include<bits/stdc++.h>
//amazon interview que
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  public:
    //for concatenation of 2 lists
    Node *solve(Node* leftList,Node* rightList){
        if(!leftList)
            return rightList;
        if(!rightList)
            return leftList;
        Node *leftLast = leftList->left;
        Node *rightLast = rightList->left;
        //last node of left list with first node of right list
        leftLast->right = rightList;
        rightList->left = leftLast;

        //left of first nodes points to last node in list
        leftList->left = rightLast;
        //right of last node points to first node in list
        rightLast->right = leftList;
        return leftList;
    }
    Node *bTreeToCList(Node *root)
    {
        if(!root)  
            return NULL;
        Node *left = bTreeToCList(root->left);
        Node *right = bTreeToCList(root->right);
        //for LL to be circular
        root->left = root->right = root;
        return solve(solve(left,root),right);//left with curr node and returned list with right list
    }
};