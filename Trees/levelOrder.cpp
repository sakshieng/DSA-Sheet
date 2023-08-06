#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// Level order traversal of a tree is breadth first traversal for the tree
/*
Input:  root = [3,9,20,null,null,15,7]
        3
    9       20
        15      7
Output: [[3],[9,20],[15,7]]
*/
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main()
{
    Node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    cout << "Level Order traversal of binary tree is \n";
    levelOrder(root);
    return 0;
}