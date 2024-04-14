#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void postorderTraversal(Node *root)
{
    if (!root)
        return;

    // recur on left subtree
    postorderTraversal(root->left);

    // then recur on right subtree
    postorderTraversal(root->right);

    // print the root's data
    cout << root->data << " ";
}

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
};
