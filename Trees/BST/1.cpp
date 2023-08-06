#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

class treeNode
{
private:
    int data;
    treeNode *left;
    treeNode *right;
public:
    treeNode(){};
    treeNode(int new_data)
    {
        data=new_data;
        left=right=NULL;
    }
    void search(treeNode* root,int val);
    bool isBST(treeNode *root);
    treeNode *insert(treeNode *root,int new_data);
    vector<vector<int>> levelOrder(treeNode *root);
    void inOrder(treeNode* root);
    treeNode* minVal(treeNode* root);
    void maxVal(treeNode* root);
    treeNode* Delete(treeNode* root, int val);
};

bool treeNode::isBST(treeNode *root)
{
    if(!root) return 1;
    if(root->left!=NULL && root->left->data>root->data) return 0;
    if(root->right!=NULL && root->right->data<root->data) return 0;
    return (isBST(root->left) && isBST(root->right));
}
void treeNode::search(treeNode* root,int val)
{
    if(!root) 
    {
        cout<<"Not found";
        return;
    }
    if(root->data>val) search(root->left,val);
    else if(root->data<val) search(root->right,val);
    else if(root->data==val) {
        cout<<"Found data";
        return;
    }
}
treeNode* treeNode::insert(treeNode *root,int new_data)
{
    if(!root)
    {
        return new treeNode(new_data);
    }   
    if(new_data>root->data) root->right = insert(root->right,new_data);
    if(new_data<root->data) root->left = insert(root->left,new_data);
    return root;
}
vector<vector<int>> treeNode::levelOrder(treeNode *root)
{
    if(!root) return {};
    vector<vector<int>>ans;
    queue<treeNode *>q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        vector<int>level;
        for (int i = 0; i < n; i++)
        {
            treeNode *tmp=q.front();
            q.pop();
            level.push_back(tmp->data);
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
        }
        ans.push_back(level);
    }
    return ans;
}

void treeNode::inOrder(treeNode* root)
{
    if(!root) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
treeNode* treeNode::minVal(treeNode* root)
{
    if(!root->left) {
        // cout<<root->data; 
        // cout<<endl;
        return root;
    }
    minVal(root->left);
}

void treeNode::maxVal(treeNode* root)
{
    if(!root->right) {
        cout<<root->data; 
        cout<<endl;
        return;
    }
    maxVal(root->right);
}
treeNode* treeNode::Delete(treeNode* root,int val)
{
    if(!root) return NULL;
    if(root->data>val) root->left = Delete(root->left,val);
    if(root->data<val) root->right = Delete(root->right,val);
    else 
    {
        // case 1:leaf node delete
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        } 
        // case 2:having one child
        else if(root->left == NULL && root->right != NULL){
            treeNode *tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->left != NULL && root->right == NULL){
            treeNode *tmp=root->left;
            free(root);
            return tmp;
        }
        // case 3:having two childs
        treeNode* tmp=minVal(root->right);
        root->data = tmp->data;
        root->right=Delete(root->right,tmp->data);
    }
    return root;
}
int main()
{
    treeNode tree;
    treeNode* root = NULL;
    root=tree.insert(root,10); 
    tree.insert(root,6);
    tree.insert(root,4);
    tree.insert(root,15);   
    tree.insert(root,3);   
    vector<vector<int>>disp = tree.levelOrder(root);
    tree.inOrder(root);
    cout<<"\n";
    for(auto &i: disp)
    {
        cout<<"[ ";
        for(auto &j : i){ 
            cout<<j<<" ";
        }
        cout<<" ]";
    }
    tree.Delete(root,4);
    cout<<"\n";
    tree.inOrder(root);
    cout<<"\n";
    return 0;
}