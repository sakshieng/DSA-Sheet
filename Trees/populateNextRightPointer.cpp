#include<bits/stdc++.h>
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        queue<Node*>q;
        q.push(root);
        while (!q.empty())
        {
            //go to right 
            Node* rightNode = nullptr;
            for(int i = q.size();i>0;i--){//traversing each level
                auto curr = q.front();
                q.pop();
                // set its next pointer to rightNode & update rightNode as cur for next iteration
                curr->next = rightNode;
                rightNode = curr;
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
        return root;
    }
};
//we need to populate next pointer of each node with nodes that occur to its immediate right on same level do right-to-left BFS 