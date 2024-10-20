//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}




vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    bool ltr=0;
    vector<int> temp;
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL){
            if(ltr==0){
                reverse(temp.begin(), temp.end());
                ltr=1;
            }else{
                ltr=0;
            }
            ans.insert(ans.end(),temp.begin(), temp.end());
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            } 

        }
        else{
           temp.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
}
