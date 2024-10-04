#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node(int data){
        this->data = data;
    }
    Node(int data, vector<Node*> children){
        this->data = data;
        this->children = children;
    }
};
//traversal techniques
void preorder(Node* root){
    if (root == NULL) return;
    cout << root->data << " ";
    for (Node* child : root->children) {
        preorder(child);
    }
}
void postorder(Node* root){
    if(root==NULL) return;
    for(Node* child:root->children){
        postorder(child);
    }
    cout<<root->data<<" ";
}
void levelOrder(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        for(Node* child:curr->children){
            q.push(child);
        }
    }
}
void levelOrderLineWise(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            for(Node* child:curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}
//for inorder traversal recursviely visit first half of children visit root recursively visit the second half 
void inorder(Node* root){
    if(root == NULL)
        return;
    int n = root->children.size();
    for (int i = 0; i < n/2; i++)
    {
        inorder(root->children[i]);
    }
    cout<<root->data<<" ";
    for(int i = n/2;i < n;++i){
        inorder(root->children[i]);
    }
}
int findHeight(Node* root){
    if(root == NULL) return 0;
    int maxChildHeight = 0;
    for(Node* child:root->children){
        maxChildHeight = max(maxChildHeight, findHeight(child));
    }
    return maxChildHeight+1;//add 1 for curr node
}
Node* findLCA(Node* root,Node* p,Node* q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;
    int cnt = 0;
    Node* temp = NULL;
    for(Node* child:root->children){
        Node *res = findLCA(child,p,q);
        if(res != NULL){
            cnt++;
            temp = res;
        }
    }
    if(cnt == 2) return root;//this enusres that p&q are found in same subtree
    return temp;
}
int main() 
{
   Node* root = new Node(1, {new Node(2), new Node(3), new Node(4)});
    cout << "Preorder Traversal: ";
    preorder(root);//TC O(n) SC O(H)
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;//TC O(n) SC O(H)

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;//TC O(n) SC O(W) maximum width of the tree

    cout << "Line wise level order Traversal: ";
    levelOrderLineWise(root);//TC O(n) SC O(W)

    cout << "Inorder-like Traversal: ";
    inorder(root);//TC O(n) SC O(H)

    cout << "Height of the tree: " << findHeight(root);//TC O(n) SC O(H)

    Node* lca = findLCA(root, new Node(2), new Node(3));
    cout << "LCA of 2 and 3: " << lca->data;//TC O(n) SC O(n)
    cout << endl;
   return 0;
}