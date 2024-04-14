// https://leetcode.com/discuss/interview-question/algorithms/125080/linkedin-generate-a-binary-tree-from-parent-child-relationship
/*
Given a list of child->parent relationships, build a binary tree out of it. All element Ids inside tree are unique.

Example:

Given following relns:

Child Parent IsLeft
15 20 true
19 80 true
17 20 false
16 80 false
80 50 false
50 -1 false
20 50 true
ans:
    50
   /  \
  20   80
 / \   / \
15 17 19 16
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int data){
        this->data;
    }
};


// Function to perform an in-order traversal of binary tree
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    map<int, Node*> mp; // Moved map outside the loop

    for (int i = 0; i < n; ++i) {
        int a, b;
        bool isLeft;
        cin >> a >> b >> isLeft;

        if (mp.count(a) == 0) {
            Node* tmp = new Node(a);
            mp[a] = tmp;
        }
        if (b == -1) {
            root = mp[a];
        } else {
            if (mp.count(b) == 0) {
                Node* tmp = new Node(b);
                mp[b] = tmp;
            }
            if (isLeft)
                mp[b]->left = mp[a];
            else
                mp[b]->right = mp[a];
        }
    }

    inorder(root);
    return 0;
}
